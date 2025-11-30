#!/bin/bash
set -euo pipefail

ACCOUNT=fc_cosi
WALL=01:30:00
LOG_DIR="${LOG_DIR:-logs}"
mkdir -p "$LOG_DIR"

# CPU rules
CPUS_A5000=4
CPUS_L40=8
CPUS_A40=8
CPUS_2080TI=2
CPUS_1080TI=2

declare -a JOBS=()

##############################################
# submit(partition, qos, gres_string, gpus, cpus_per_task)
##############################################
submit() {
    local partition="$1"
    local qos="$2"
    local gres="$3"
    local gpus="$4"
    local cpt="$5"

    sbatch --parsable \
        --account="$ACCOUNT" \
        --partition="$partition" \
        --qos="$qos" \
        --time="$WALL" \
        --nodes=1 \
        --gres="$gres" \
        --ntasks-per-node="$gpus" \
        --cpus-per-task="$cpt" \
        --output="${LOG_DIR}/slurm-%j.out" \
        --error="${LOG_DIR}/slurm-%j.err" \
        payload.sh
}

echo "Submitting multi-partition GPU candidates..."

# savio4_gpu A5000
for g in 1; do
    jid=$(submit "savio4_gpu" "a5k_gpu4_normal" "gpu:A5000:${g}" "$g" "$CPUS_A5000")
    echo "savio4_gpu A5000 (${g} GPU) -> $jid"
    JOBS+=("$jid")
done

# savio4_gpu L40
for g in 1; do
    jid=$(submit "savio4_gpu" "savio_lowprio" "gpu:L40:${g}" "$g" "$CPUS_L40")
    echo "savio4_gpu L40 (${g} GPU lowprio) -> $jid"
    JOBS+=("$jid")
done

# savio3_gpu A40
for g in 1; do
    jid=$(submit "savio3_gpu" "a40_gpu3_normal" "gpu:A40:${g}" "$g" "$CPUS_A40")
    echo "savio3_gpu A40 (${g} GPU) -> $jid"
    JOBS+=("$jid")
done

# savio3_gpu GTX2080Ti
for g in 1; do
    jid=$(submit "savio3_gpu" "gtx2080_gpu3_normal" "gpu:GTX2080TI:${g}" "$g" "$CPUS_2080TI")
    echo "savio3_gpu GTX2080Ti (${g} GPU) -> $jid"
    JOBS+=("$jid")
done

# savio2_1080ti GTX1080Ti
for g in 1; do
    jid=$(submit "savio2_1080ti" "savio_normal" "gpu:GTX1080TI:${g}" "$g" "$CPUS_1080TI")
    echo "savio2_1080ti (${g} GPU) -> $jid"
    JOBS+=("$jid")
done

echo
echo "Polling every 10 seconds… waiting for the first job to start."
echo

##############################################
# Poll until one job becomes RUNNING
##############################################
keep=""
while true; do
    echo "===== Job Status @ $(date '+%Y-%m-%d %H:%M:%S') ====="
    squeue -h -j "$(IFS=,; echo "${JOBS[*]}")" -o "%i %T %R"
    echo "====================================================="
    echo

    running=$(squeue -h -j "$(IFS=,; echo "${JOBS[*]}")" -o "%i %T" \
              | awk '$2=="RUNNING"{print $1; exit}')

    if [[ -n "$running" ]]; then
        keep="$running"
        echo "Job $keep is RUNNING!"
        echo

        ##############################################
        # GPU + node details
        ##############################################
        echo "===== GPU Allocation Details for job $keep ====="

        node=$(squeue -j "$keep" -h -o "%N")
        echo "Node: $node"

        gres=$(scontrol show job "$keep" | awk -F= '/Gres=/{print $2}' | cut -d' ' -f1)
        echo "GRES: $gres"

        echo "================================================="
        echo
        echo "Cancelling all other jobs..."
        break
    fi

    sleep 10
done

##############################################
# Cancel all other jobs
##############################################
for jid in "${JOBS[@]}"; do
    if [[ "$jid" != "$keep" ]]; then
        scancel "$jid" || true
    fi
done

echo
echo "===================================="
echo "   Live ERROR log for job $keep"
echo "===================================="
echo

##############################################
# Tail the real Slurm **error** file
##############################################

sleep 2

err_file=$(scontrol show job "$keep" | awk -F= '/StdErr=/{print $2}')

if [[ ! -f "$err_file" ]]; then
    echo "Waiting for error file to appear..."
    for i in {1..20}; do
        sleep 1
        [[ -f "$err_file" ]] && break
    done
fi

if [[ -f "$err_file" ]]; then
    echo "Tailing $err_file"
    echo "----------------------------------------"
    tail -n +1 -f "$err_file"
else
    echo "ERROR: Could not find slurm error file"
fi

exit 0