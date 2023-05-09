#include "random_initialization.h"
#include <random>

std::vector<Point> random_initialization(const std::vector<Point>& data, int k) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, data.size() - 1);

    std::vector<Point> centroids;
    for (int i = 0; i < k; ++i) {
        centroids.push_back(data[dis(gen)]);
    }

    return centroids;
}
