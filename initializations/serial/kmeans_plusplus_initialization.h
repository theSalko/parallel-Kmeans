#pragma once
#include <vector>
#include "../../data_classes/point.h"

std::vector<Point> kmeans_plusplus_initialization(const std::vector<Point>& data, int k);
