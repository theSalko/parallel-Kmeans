#include <iostream>

// #include "initializations/random_initialization.h"
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


int main() {
    int k = 3;
    int max_iterations = 300;
    std::string file_path = "path/to/your/datafile.csv";

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
