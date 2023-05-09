#include <iostream>

#include "algorithms/serial/lloyd_kmeans.h"
#include "utils/csv_utils.h"

int main() {


    // std::string file_path = "/mnt/c/Users/salko/Downloads/USCensus1990.data.txt";
    
    std::string file_path = "data.csv";
    std::vector<Point> data = read_csv(file_path, true);

    // Parameters for the k-means algorithm
    int k = 3; // Number of clusters
    int max_iterations = 100;

    // Create a LloydKMeans object and fit the data
    LloydKMeans lloyd_kmeans(k, max_iterations);
    lloyd_kmeans.fit(data);

    // Get the final centroids
    const auto& centroids = lloyd_kmeans.get_centroids(); 
    
    //std::vector<Point>& centroids = lloyd_kmeans.get_centroids();


    std::cout << "Cluster heterogeneity: " << lloyd_kmeans.compute_cluster_heterogeneity(data) << std::endl;

    std::string output_file_path = "output.csv";
    csv_write(output_file_path, data, centroids);

    return 0;

    // // Print the final centroids
    // std::cout << "Final centroids:\n";
    // for (const auto& centroid : centroids) {
    //     std::cout << centroid << std::endl;
    // }

    // return 0;

    // KMeansRandom kmeans_random(k, max_iterations);
    // KMeansPlusPlus kmeans_plusplus(k, max_iterations);

    // std::vector<Point> data = kmeans_random.read_csv(file_path);
    
    // kmeans_random.fit(data);
    // std::vector<Point> random_centroids = kmeans_random.get_centroids();
    
    // kmeans_plusplus.fit(data);
    // std::vector<Point> kmeans_plusplus_centroids = kmeans_plusplus.get_centroids();

    // std::cout << "Random Initialization Centroids:" << std::endl;
    // for (const Point& centroid : random_centroids) {
    //     std::cout << centroid << std::endl;
    // }

    // std::cout << "KMeans++ Initialization Centroids:" << std::endl;
    // for (const Point& centroid : kmeans_plusplus_centroids) {
    //     std::cout << centroid << std::endl;
    // }

    return 0;
}


















//// #include "initializations/random_initialization.h"
// #include "initializations/kmeans_plusplus_initialization.h"
// #include "updates/serial/basic_update.h" // Include basic_update

// class KMeansRandom : public KMeans {
// public:
//     KMeansRandom(int k, int max_iterations) : KMeans(k, max_iterations) {}

// protected:
//     void initialize_centroids(const std::vector<Point>& data) {
//         centroids_ = random_initialization(data, k_);
//     }

//     double update_centroids(std::vector<Point>& data) {
//         return basic_update_centroids(data, centroids_);
//     }
// };

// class KMeansPlusPlus : public KMeans {
// public:
//     KMeansPlusPlus(int k, int max_iterations) : KMeans(k, max_iterations) {}

// protected:
//     void initialize_centroids(const std::vector<Point>& data) {
//         centroids_ = kmeans_plusplus_initialization(data, k_);
//     }

//     double update_centroids(std::vector<Point>& data) {
//         return basic_update_centroids(data, centroids_);
//     }
// };

