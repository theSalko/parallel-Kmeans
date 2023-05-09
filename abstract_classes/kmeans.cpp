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


// Read data points from a CSV file and store them in a vector
std::vector<Point> KMeans::read_csv(const std::string& file_path) const {
    std::vector<Point> data;
    std::ifstream file(file_path);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file at " << file_path << std::endl;
        return data;
    }

    // Read lines from the file
    std::string line;
    while (std::getline(file, line)) {
        std::vector<double> coordinates;
        std::stringstream line_stream(line);
        std::string value;

        
        // Split the line by commas and store the values as coordinates
        while (std::getline(line_stream, value, ',')) {
            coordinates.push_back(std::stod(value));
        }


        // Add the point with the coordinates to the data vector
        data.emplace_back(coordinates);
    }

    // Close the file
    file.close();
    return data;
}
