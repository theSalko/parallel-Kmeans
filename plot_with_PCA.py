import pandas as pd
import numpy as np
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

import argparse

def read_csv(file_path):
    with open(file_path, 'r') as f:
        lines = f.readlines()

    data_start = 0
    centroids = []
    data = []
    for i, line in enumerate(lines):
        if line.startswith("\n"):
            data_start = i + 2
            break
        elif i > 0:
            coords = line.strip().strip("()").split(", ")
            centroids.append([float(c) for c in coords])

    for line in lines[data_start:]:
        if line.startswith("Data"):
            break
        # print(line)
        # print(centroids, "is centroids")
        coords, cluster = line.strip().split(", Cluster: ")
        coords = coords.strip("()").split(", ")
        data.append([float(c) for c in coords] + [int(cluster)])

    return np.array(centroids), np.array(data)

def main():

    
    parser = argparse.ArgumentParser(description="Visualize KMeans clustering output.")
    parser.add_argument("input_file_path", help="Input file path of the CSV file containing clustering output.")
    parser.add_argument("-pca", action="store_true", help="Apply PCA to reduce dimensions to 2 before plotting.")
    args = parser.parse_args()

    input_file_path = args.input_file_path
    use_pca = args.pca


    centroids, data = read_csv(input_file_path)

    if use_pca:
        # Apply PCA
        pca = PCA(n_components=2)
        transformed_data = pca.fit_transform(data[:, :-1])
        transformed_centroids = pca.transform(centroids)
        axis_label = "PCA Component"
        output_filename = 'output_pca.png'
        title = "2D PCA Visualization of Clusters"
        
    else:
        transformed_data = data[:, :-1]
        transformed_centroids = centroids
        axis_label = "Dimension"
        output_filename = 'output.png'
        title = "2D Visualization of Clusters"
        




    # Plot results
    plt.scatter(transformed_data[:, 0], transformed_data[:, 1], c=data[:, -1], cmap="viridis", marker="o", s=50, alpha=0.6, edgecolors="w", linewidths=0.5)
    plt.scatter(transformed_centroids[:, 0], transformed_centroids[:, 1], c="red", marker="x", s=200, alpha=1, edgecolors="k", linewidths=2)

    plt.title(title)
    plt.xlabel(f"{axis_label} 1")
    plt.ylabel(f"{axis_label} 2")
    plt.savefig(output_filename, dpi=300, bbox_inches='tight')
    # plt.show()
    # Save the plot to a file as a PNG
    # plt.savefig(file_name, dpi=300, bbox_inches='tight')


if __name__ == "__main__":

    main()
