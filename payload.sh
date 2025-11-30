#!/bin/bash
#SBATCH --job-name=payload
#SBATCH --account=fc_cosi
#SBATCH --partition=savio4_gpu
#SBATCH --time=08:00:00
#SBATCH --nodes=1

set -euo pipefail

#############################
# Environment setup (UV + CUDA 12.3)
#############################

# Sync dependencies from pyproject.toml
uv sync

# Activate your uv-managed venv
source .venv/bin/activate

#############################
# Run workload
#############################
srun -l uv run main.py

