#pragma once
#include <vector>
#include <string>
#include "../data_classes/point.h"


class KMeans {
public:
    KMeans(int k, int max_iterations);

    void fit(std::vector<Point>& data);
    const std::vector<Point>& get_centroids() const;
    double compute_cluster_heterogeneity(const std::vector<Point>& data) const;

protected:
    virtual void initialize_centroids(const std::vector<Point>& data) = 0;
    virtual void assign_clusters(std::vector<Point>& data) = 0;
    virtual double update_centroids(std::vector<Point>& data) = 0;

    int k_; // Number of centroids
    int max_iterations_; // Maximum number of iterations
    std::vector<Point> centroids_; // The centroids
};

