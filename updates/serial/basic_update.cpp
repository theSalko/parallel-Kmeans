// #include "basic_update.h"
// #include <vector>

// double basic_update_centroids(std::vector<Point>& centroids, std::vector<Point>& data) {
//     return 0;
//     // ... Implementation remains the same
// }

#include "basic_update.h"
#include <vector>
#include <limits>
#include <cmath>

double basic_update_centroids(std::vector<Point>& centroids,
                              std::vector<Point>& data) {
    // Create a vector to store the new centroids
    std::vector<Point> new_centroids(centroids.size(),
                                     Point(std::vector<double>(centroids[0].get_coordinates().size(), 0)));

    // Create a vector to store the number of points in each cluster
    std::vector<int> cluster_sizes(centroids.size(), 0);

    // Iterate through the data points
    for (const auto& point : data) {

        // Get the cluster of the current point
        int cluster = point.get_cluster();

        // Update the new centroid for the cluster by 
        //  adding the point's coordinates
        new_centroids[cluster].add(point);

        // Increment the number of points in the cluster
        cluster_sizes[cluster]++;
    }


    // Calculate the new centroids by dividing the sum of the points' coordinates
    //  by the number of points in each cluster
    for (size_t i = 0; i < new_centroids.size(); ++i) {
        new_centroids[i].divide_coordinates_by(cluster_sizes[i]);
    }

    // Calculate the total change in the centroids' positions
    double total_change = 0.0;
    for (size_t i = 0; i < centroids.size(); ++i) {
        total_change += centroids[i].distance_to(new_centroids[i]);
    }

    // Update the centroids with the new positions
    centroids = new_centroids;

    return total_change;
}

