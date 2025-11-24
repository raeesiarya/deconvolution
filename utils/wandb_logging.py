import wandb
import torch

def tensor_to_wandb_image(tensor: torch.Tensor, caption: str) -> wandb.Image:
    """Convert a (1,1,H,W) or (1,1,K,K) tensor to a wandb.Image."""
    array = tensor.detach().cpu().squeeze().numpy()
    # Normalize array for visualization
    arr_min = array.min()
    arr_max = array.max()
    if arr_max > arr_min:
        array = (array - arr_min) / (arr_max - arr_min)
    else:
        array = array * 0.0  # fallback for constant arrays

    return wandb.Image(array, caption=caption)
