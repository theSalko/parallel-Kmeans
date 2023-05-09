#include "kmeans.h"
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

KMeans::KMeans(int k, int max_iterations) : k_(k), max_iterations_(max_iterations) {}

void KMeans::fit(std::vector<Point>& data) {

    // Step 1: Initialize the centroids
    initialize_centroids(data);

    // Go over the data at most max_iterations_ number of times
    for (int iter = 0; iter < max_iterations_; ++iter) {
        
        // Step 2: Assign the data to the clusters
        assign_clusters(data);
        
        // Step 3: Update the centroids
        double centroid_movement = update_centroids(data);

        //Step 4: Check for convergence (if the centroids move less than some threshold, break out)
        if (std::fabs(centroid_movement) < 1e-6) {
            break;
        }
    }
}



// Getter function for the centroids
const std::vector<Point>& KMeans::get_centroids() const {
    return centroids_;
}

// Computes the cluster heterogeneity of the data points given the cluster centers and assigned
// Clusters of the data
double KMeans::compute_cluster_heterogeneity(const std::vector<Point>& data) const {
    double heterogeneity = 0.0;

    for (const auto& point : data) {
        int cluster = point.get_cluster();
        double distance = point.distance_to(centroids_[cluster]);
        heterogeneity += distance * distance;
    }

    return heterogeneity;
}
