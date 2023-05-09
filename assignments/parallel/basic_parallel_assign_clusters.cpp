#include "basic_parallel_assign_clusters.h"
#include <limits>
#include "parallel.h"

// This function takes a vector of data points and a vector of centroids as input.
//  Assigns the closest centroid to each of the data points in parallel
void basic_parallel_assign_clusters(std::vector<Point>& data, const std::vector<Point>& centroids) {

    // For each data point, find the centroid closest to it 
    //  and assign the point to that cluster.
    for (Point& point : data) {

        // Initialize the minimum distance to a very large number 
        //  and the closest centroid to an invalid value.
        double min_distance = std::numeric_limits<double>::max();
        int closest_centroid = -1;

        // Loop over all the centroids 
        //  and find the one closest to the current point.
        for (size_t j = 0; j < centroids.size(); ++j) {

            // Calculate the distance between the current point 
            //  and the jth centroid.
            double distance = point.distance_to(centroids[j]);

            // If this distance is less than the current minimum, 
            //  update the minimum distance and closest centroid.
            if (distance < min_distance) {
                min_distance = distance;
                closest_centroid = j;
            }
        }


        // Assign the current point to the closest centroid's cluster.
        point.set_cluster(closest_centroid);
    }
}
