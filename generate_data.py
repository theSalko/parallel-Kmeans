import numpy as np
import pandas as pd
from sklearn.datasets import make_blobs

def generate_data(n_samples=300, n_features=2, centers=3, random_state=None, file_name="data.csv"):
    data, labels = make_blobs(n_samples=n_samples, n_features=n_features, centers=centers, random_state=random_state)
    df = pd.DataFrame(data)
    df.to_csv(file_name, index=False, header=False)

def main():
    generate_data(n_samples=300, n_features=2, centers=3, random_state=42, file_name="data.csv")

if __name__ == "__main__":
    main()
