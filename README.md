# Blind Deconvolution Playground

Small research playground for single-image blind deconvolution. The pipeline builds a synthetic measurement (blur + noise), then jointly optimizes the latent sharp image and PSF kernel with a MAP objective. Metrics and qualitative outputs are logged to Weights & Biases for quick inspection.

## What’s inside
- `main.py`: entrypoint; loads images from `images/`, synthesizes blur with a Gaussian PSF + noise, runs optimization, and logs PSNR/SSIM + visuals to W&B.
- `blind_deconvolution/`: core solver (`BlindDeconvolver`), forward model, PSF generators (Gaussian/motion/disk/delta), and priors (pink-noise and a diffusion prior stub).
- `utils/`: image I/O and path helpers, NumPy↔Torch converters, metrics (PSNR/SSIM), and W&B image helpers.
- `images/`: sample `synthetic/` patterns and a `real/` folder for your own data. Supported extensions: png/jpg/jpeg/tif/tiff/bmp.

## Setup (UV + Weights & Biases)
1. Install UV if you don’t have it.
2. Create and activate the env:
   ```bash
   uv venv
   uv sync
   source .venv/bin/activate
   ```
3. Install dependencies in editable mode:
   ```bash
   uv add pyproject.toml
   ```
4. Authenticate with Weights & Biases (or set `WANDB_MODE=offline` if you prefer no logging):
   ```bash
   wandb login
   ```

## Running the demo
Place one or more grayscale-compatible images in `images/` (subfolders are picked up). Then run:
```bash
python main.py
```
What happens:
- Each image is converted to grayscale, normalized, and blurred with a Gaussian PSF (`kernel_size` and `sigma` defined in code) plus small Gaussian noise.
- The solver performs gradient-based joint optimization of the image (`x`) and kernel (`k`) using Adam.
- PSNR/SSIM, loss curves, reconstructions, and kernels are logged to W&B per image; mean PSNR/SSIM are stored in the run summary.

## Tuning / extending
- Hyperparameters live in the `BlindDeconvConfig` in `main.py`: iteration count, learning rates (`lr_x`, `lr_k`), kernel size, and regularization weights (`lambda_k_l2`, `lambda_k_center`, `lambda_pink`, `lambda_diffusion`).
- Image priors: plug a custom `image_prior_fn` into the config (the default is none). A diffusion-based prior hook exists in `blind_deconvolution/priors/diffusion.py`—replace the stub with your model’s score function.
- Kernels: swap the synthetic blur by editing the PSF generator in `main.py` (e.g., use `motion_psf` or `disk_psf`).
- Logging: adjust what’s sent to W&B in `main.py` or disable by exporting `WANDB_MODE=offline` before running.

## Notes
- Currently optimized for single-channel images; extend the forward model if you need RGB.
- The pipeline runs on CPU by default; set `device` in `main.py` to "cuda" if available.
