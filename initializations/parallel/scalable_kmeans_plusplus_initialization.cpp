#include <random>

#include "scalable_kmeans_plusplus_initialization.h"

std::vector<Point> scalable_kmeans_plusplus_initialization(const std::vector<Point>& data, int k) {
    
    // TODO
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, data.size() - 1);

    std::vector<Point> centroids;
    for (int i = 0; i < k; ++i) {
        centroids.push_back(data[dis(gen)]);
    }

    return centroids;
}
