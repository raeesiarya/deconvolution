import torch
import torch.nn.functional as F

##############################
# Numpy <-> Torch helpers
##############################


def numpy_image_to_tensor(x_np) -> torch.Tensor:
    """
    Convert a 2D numpy image in [0,1] to a torch tensor (1,1,H,W).
    """
    if x_np.ndim != 2:
        raise ValueError("Expected 2D grayscale numpy array.")
    x_t = torch.from_numpy(x_np).float()
    x_t = x_t.unsqueeze(0).unsqueeze(0)  # (H,W) -> (1,1,H,W)
    return x_t


def numpy_kernel_to_tensor(k_np) -> torch.Tensor:
    """
    Convert a 2D numpy PSF to a torch tensor (1,1,Kh,Kw).
    """
    if k_np.ndim != 2:
        raise ValueError("Expected 2D numpy kernel.")
    k_t = torch.from_numpy(k_np).float()
    k_t = k_t.unsqueeze(0).unsqueeze(0)  # (Kh,Kw) -> (1,1,Kh,Kw)
    return k_t