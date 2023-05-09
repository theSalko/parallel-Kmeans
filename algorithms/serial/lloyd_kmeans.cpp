#include "lloyd_kmeans.h"
#include "initializations/serial/random_initialization.h"
#include "assignments/serial/basic_assign_clusters.h"
#include "updates/serial/basic_update.h"


LloydKMeans::LloydKMeans(int k, int max_iterations) : KMeans(k, max_iterations) {
}

void LloydKMeans::initialize_centroids(const std::vector<Point>& data) {
    // Implement the centroid initialization method here
    centroids_ = random_initialization(data, k_);
}

void LloydKMeans::assign_clusters(std::vector<Point>& data) {
    // Implement the cluster assignment method here
    basic_assign_clusters(data, centroids_);
}

double LloydKMeans::update_centroids(std::vector<Point>& data) {
    // Implement the centroid update method here
    // Return the total change in the centroids' positions
    return basic_update_centroids(centroids_, data);
}
