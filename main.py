from utils.image_paths import list_image_paths
from utils.image_io import load_image


def main():
    paths = list_image_paths()
    for path in paths:
        print(path)
        img = load_image(path, mode="torch")
        print(img)
        print(img.shape)

if __name__ == "__main__":
    main()
