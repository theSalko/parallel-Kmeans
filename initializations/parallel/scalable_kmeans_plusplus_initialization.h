#pragma once
#include <vector>
#include "../../data_classes/point.h"

std::vector<Point> scalable_kmeans_plusplus_initialization(const std::vector<Point>& data, int k, double oversampling_factor);
