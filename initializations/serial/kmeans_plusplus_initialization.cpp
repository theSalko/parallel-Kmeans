#include "kmeans_plusplus_initialization.h"
#include <random>
#include <limits>
#include <numeric>

std::vector<Point> kmeans_plusplus_initialization(const std::vector<Point>& data, int k) {
    // Initialize random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, data.size() - 1);

    // Initialize the centroids vector and select the first centroid randomly from the data
    std::vector<Point> centroids;
    centroids.push_back(data[dis(gen)]);

    // Initialize the vector to store distances from data points to the closest centroid
    std::vector<double> distances(data.size(), 0.0);

    // Iterate through the remaining centroids
    for (int i = 1; i < k; ++i) {
        // For each data point, find the distance to the closest centroid
        for (size_t j = 0; j < data.size(); ++j) {
            double min_distance_to_centroid = std::numeric_limits<double>::max();

            // Calculate the distance between the data point and each existing centroid
            for (const Point& centroid : centroids) {
                double distance = data[j].distance_to(centroid);
                min_distance_to_centroid = std::min(min_distance_to_centroid, distance);
            }

            // Store the distance to the closest centroid
            distances[j] = min_distance_to_centroid;
        }

        // Calculate the sum of squared distances
        double sum_squared_distances = 0.0;
        for (const double distance : distances) {
            sum_squared_distances += distance * distance;
        }

        // Generate a random number between 0 and the sum of squared distances
        std::uniform_real_distribution<> dis_real(0, sum_squared_distances);
        double random_value = dis_real(gen);

        // Select the data point as the next centroid based on the probability distribution
        double cumulative_sum = 0.0;
        size_t next_centroid_index = 0;
        for (size_t j = 0; j < data.size(); ++j) {
            cumulative_sum += distances[j] * distances[j];
            if (cumulative_sum >= random_value) {
                next_centroid_index = j;
                break;
            }
        }

        centroids.push_back(data[next_centroid_index]);
    }

    return centroids;
}
