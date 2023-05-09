#include "point.h"


// Define the constructor for the Point class
Point::Point(const std::vector<double>& coordinates) : coordinates_(coordinates), cluster_(-1) {}

// Return the coordinates of the point
const std::vector<double>& Point::get_coordinates() const {
    return coordinates_;
}

// Set the coordinates of the point
void Point::set_coordinates(const std::vector<double>& coordinates) {
    coordinates_ = coordinates;
}

// Return the index of the cluster to which the point belongs
int Point::get_cluster() const {
    return cluster_;
}

// Set the index of the cluster to which the point belongs
void Point::set_cluster(int cluster) {
    cluster_ = cluster;
}

// Calculate the Euclidean distance between the
//  current point and another point
// 
// Returns the distance as a double
double Point::distance_to(const Point& other) const {
    double sum = 0.0;
    for (size_t i = 0; i < coordinates_.size(); ++i) {
        double diff = coordinates_[i] - other.coordinates_[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

// Add another point to the current point. Works like adding two vectors together
void Point::add(const Point& other) {
    const std::vector<double>& other_coordinates = other.get_coordinates();
    
    
    // Check that the two points have the same number of coordinates
    if (coordinates_.size() != other_coordinates.size()) {
        throw std::runtime_error("Points have different dimensions and cannot be added.");
    }

    
    // Add each coordinate of the other point to the 
    //  corresponding coordinate of the current point
    for (size_t i = 0; i < coordinates_.size(); ++i) {
        coordinates_[i] += other_coordinates[i];
    }

}


// Divide each coordinate of the point by a scalar value.
void Point::divide_coordinates_by(int n) {
    for (size_t i = 0; i < coordinates_.size(); ++i) {
        coordinates_[i] /= n;
    }
}


// Define the output operator for the Point class.
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(";

    // Output each coordinate of the point.
    for (size_t i = 0; i < point.coordinates_.size(); ++i) {
        os << point.coordinates_[i];
        if (i != point.coordinates_.size() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}
