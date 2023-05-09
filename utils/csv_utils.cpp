// csv_utils.cpp
#include "csv_utils.h"
#include <fstream>
#include <sstream>
#include "../data_classes/point.h"

std::vector<Point> read_csv(const std::string& file_path, bool skip_header) {
    std::vector<Point> data;
    std::ifstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file at " << file_path << std::endl;
        return data;
    }

    std::string line;
    
    // Skip the first line if skip_header is true
    if (skip_header && std::getline(file, line)) {
        // Do nothing, just skip the line
    }



    while (std::getline(file, line)) {
        std::vector<double> coordinates;
        std::stringstream line_stream(line);
        std::string value;

        while (std::getline(line_stream, value, ',')) {
            coordinates.push_back(std::stod(value));
        }

        data.emplace_back(coordinates);
    }

    file.close();
    return data;
}




void csv_write(const std::string& file_path, const std::vector<Point>& data, const std::vector<Point>& centroids) {
    std::ofstream output_file(file_path);

    if (!output_file.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + file_path);
    }

    // Write centroids
    output_file << "Centroids:\n";
    for (const auto& centroid : centroids) {
        output_file << centroid << "\n";
    }

    // Write data with cluster information
    output_file << "\nData with cluster assignments:\n";
    for (const auto& point : data) {
        output_file << point << ", Cluster: " << point.get_cluster() << "\n";
    }

    output_file.close();
}