
"""
synthetic_image_gen.py
Phase 1: Synthetic dataset generation for blind deconvolution project.

This module provides:
- Natural image loading utilities
- Synthetic PSF generation (Gaussian, motion, delta)
- Forward model: FFT-based convolution
- (x, y, h) sample generation + saving

Author: Arya & Dekel (Project 3)
"""

import numpy as np
from scipy.signal import fftconvolve
from skimage import io, color, img_as_float
from skimage.util import random_noise
from skimage.filters import gaussian
import os


##############################
# Image Loading
##############################

def load_image(path: str, grayscale: bool = True, normalize: bool = True) -> np.ndarray:
    """
    Loads an image from file.

    Args:
        path (str): Path to image file.
        grayscale (bool): Convert to grayscale.
        normalize (bool): Convert to float in [0,1].

    Returns:
        np.ndarray: Loaded image.
    """
    img = io.imread(path)

    if grayscale and img.ndim == 3:
        img = color.rgb2gray(img)

    if normalize:
        img = img_as_float(img)

    return img


##############################
# PSF Generators
##############################

def psf_delta(size: int = 15) -> np.ndarray:
    """
    Delta kernel (identity blur).
    """
    psf = np.zeros((size, size))
    psf[size // 2, size // 2] = 1.0
    return psf


def psf_gaussian(size: int = 15, sigma: float = 2.0) -> np.ndarray:
    """
    Generates a Gaussian blur kernel.
    """
    ax = np.linspace(-(size // 2), size // 2, size)
    xx, yy = np.meshgrid(ax, ax)
    kernel = np.exp(-(xx**2 + yy**2) / (2 * sigma**2))
    kernel /= kernel.sum()
    return kernel


def psf_motion(size: int = 15, angle: float = 0.0) -> np.ndarray:
    """
    Simple horizontal/vertical motion blur kernel.
    For more complex kernels you'll expand this later.
    """
    kernel = np.zeros((size, size))
    kernel[size // 2, :] = 1.0
    kernel /= kernel.sum()
    return kernel


##############################
# Forward Model
##############################

def apply_convolution(image: np.ndarray, psf: np.ndarray) -> np.ndarray:
    """
    Forward model: y = h * x using FFT convolution.
    """
    return fftconvolve(image, psf, mode='same')


##############################
# Sample Generator
##############################

def generate_sample(img_path: str, psf_type: str = "gaussian", save_dir: str = None) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    """
    Loads an image, applies a PSF, and returns (x, y, h).

    Args:
        img_path (str): Path to natural image.
        psf_type (str): One of ["gaussian", "motion", "delta"].
        save_dir (str or None): Directory to save results. If None, nothing is saved.

    Returns:
        (x, y, h)
    """

    x = load_image(img_path)

    # Select PSF
    if psf_type == "gaussian":
        h = psf_gaussian()
    elif psf_type == "motion":
        h = psf_motion()
    elif psf_type == "delta":
        h = psf_delta()
    else:
        raise ValueError(f"Unknown psf_type: {psf_type}")

    # Forward model
    y = apply_convolution(x, h)

    # Save results
    if save_dir is not None:
        os.makedirs(save_dir, exist_ok=True)
        io.imsave(os.path.join(save_dir, "x.png"), x)
        io.imsave(os.path.join(save_dir, "y.png"), y)
        np.save(os.path.join(save_dir, "h.npy"), h)

    return x, y, h


##############################
# CLI (Optional)
##############################

if __name__ == "__main__":
    # Example usage for quick testing:
    test_img = "example.jpg"   # Replace with your own path
    x, y, h = generate_sample(test_img, psf_type="gaussian", save_dir="sample_output")
    print("Sample generated and saved.")