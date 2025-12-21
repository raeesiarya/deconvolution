# Unsupervised Blind Deconvolution

This repo targets joint recovery of an image and its point spread function (PSF) directly from measurements. The self-calibrating idea echoes other coupled inference problems: camera poses + scene geometry in SfM [Schoenberger & Frahm, CVPR 2016], map + trajectory in SLAM [Khairuddin et al., IEEE RAM 2016], spike times + waveforms in spike sorting [Ekanadham, PhD Thesis 2015], and simultaneous eye-tracker calibration + neural decoding [Yates et al., Nat. Commun. 2023]. Here we pair a physics-based forward model (convolution with a PSF) with priors on natural images and plausible PSFs to make the blind deconvolution problem well-posed. Randomized optics offer low spatial autocorrelation (h * h ~ delta), which helps disambiguate scene content even when the exact PSF realization is unknown.

## Approach
- Forward model `y = k * x + n` (same-padding conv2d + optional Gaussian noise).
- MAP objective over `x` and `k` with kernel priors (L2, center-of-mass, autocorrelation), image priors (custom hook), pink-noise prior, and an optional diffusion prior (DDPM).
- PSF generators: Gaussian, linear motion (length/angle), atmospheric turbulence (Fried parameter + distortions), and randomized optics (band-limited Fourier phases). Identity blur is available via `psf_type="none"`.
- Testbench builds synthetic measurements for every image in `images/`, sweeps PSF types/configs, and logs PSNR/SSIM/kernel error plus artifacts to Weights & Biases.

## Repository Layout
- `launcher.sh` / `payload.sh`: Slurm submission wrapper. Fans out jobs across GPU partitions, keeps the first that starts, then runs `uv run main.py` under `srun`.
- `main.py`: Loads `.env`, logs into W&B, and iterates experiment configs from `testing/testbench_configs.py`.
- `testing/testbench.py`: Sweeps images and PSF types, synthesizes measurements, runs the solver, and logs metrics/artifacts.
- `testing/testbench_configs.py`: Preset experiment configs (iteration counts, learning rates, prior weights, kernel sizes, PSF parameters, seeds).
- `blind_deconvolution/`: Solver (`BlindDeconvolver`), forward model, MAP objective, PSF generators, and priors (pink-noise, diffusion).
- `utils/`: Image I/O and path discovery, NumPy<->Torch converters, PSNR/SSIM/kernel-error metrics, W&B helpers, and device selection.
- `image_creator/create_synthetic_images.py`: Optional synthetic patterns for `images/synthetic/`.

## Setup
- Create and sync the environment with uv:
  ```bash
  uv sync
  ```
- Add W&B credentials: set `WANDB_API_KEY=...` in `.env` or your shell. Use `WANDB_MODE=offline` to avoid uploads.

## Data
- Place images under `images/` (recursive; supports png/jpg/jpeg/tif/tiff/bmp). Sample synthetic and real images are provided.
- Generate additional patterns if needed:
  ```bash
  uv run image_creator/create_synthetic_images.py
  ```

## Running (Slurm Launcher)
1. Make the scripts executable:
   ```bash
   chmod +x launcher.sh payload.sh
   ```
2. Submit and tail logs (launcher submits to multiple GPU queues and keeps the first running job):
   ```bash
   bash launcher.sh
   ```
   - `payload.sh` performs `uv sync`, activates `.venv`, and runs the experiment sweep via `srun -l uv run main.py`.
   - Override the log directory with `LOG_DIR=... bash launcher.sh` if desired.

## Experiment Surface
- Images are discovered via `utils/image_paths.py` (recursive search under `images/`).
- PSF types: `gaussian`, `motion`, `turbulence`, `rml`, and `none` (identity). Default parameters live in `testing/testbench.py`.
- Config knobs in `testing/testbench_configs.py`: `num_iters`, `lr_x`, `lr_k`, `kernel_size`, PSF parameters (sigma, motion length/angle, turbulence Fried parameter/distortion seed, randomized-optics bandwidth/seed), prior weights (`lambda_x`, `lambda_k_l2`, `lambda_k_center`, `lambda_k_auto`, `lambda_pink`, `lambda_diffusion`), and optional run `name`.
- Measurement noise is fixed at `sigma=0.01` inside `testing/testbench.py`.
- Diffusion prior (`google/ddpm-celebahq-256`) is heavy; set `lambda_diffusion=0` to skip downloads/compute.

## Outputs and Logging
- Per image/PSF: measurements, reconstructions, estimated kernels, loss curves, PSNR, SSIM, and kernel error logged to W&B (`project=deconvolution`).
- Run summaries aggregate mean PSNR/SSIM/kernel error overall and per PSF type.
- All tensors are single-channel; extend the forward model and solver for RGB or batching as needed.

## Notes and Extensions
- Kernel constraints enforce non-negativity and unit-sum; the autocorrelation penalty helps encourage low-correlation randomized-optics PSFs (h * h ~ delta).
- Add PSF generators in `blind_deconvolution/psf_generator.py` or plug new priors via `BlindDeconvConfig.image_prior_fn` and modules under `blind_deconvolution/priors/`.
- Mind kernel size versus image size to avoid padding artifacts; defaults adapt to the selected PSF set in `testing/testbench.py`.
