#pragma once
#include "../../abstract_classes/kmeans.h"

class LloydKMeans : public KMeans {
public:
    LloydKMeans(int k, int max_iterations);

protected:
    void initialize_centroids(const std::vector<Point>& data) override;
    void assign_clusters(std::vector<Point>& data) override;
    double update_centroids(std::vector<Point>& data) override;
};
