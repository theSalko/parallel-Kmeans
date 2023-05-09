#pragma once
#include <vector>
#include <cmath>
#include <iostream>

class Point {
public:
    Point(const std::vector<double>& coordinates);

    const std::vector<double>& get_coordinates() const;
    void set_coordinates(const std::vector<double>& coordinates);

    int get_cluster() const;
    void set_cluster(int cluster);

    double distance_to(const Point& other) const;

    void add(const Point& other);
    
    void divide_coordinates_by(int n);

    friend std::ostream& operator<<(std::ostream& os, const Point& point);

private:
    std::vector<double> coordinates_;
    int cluster_;
};
