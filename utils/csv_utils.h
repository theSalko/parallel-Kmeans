// csv_utils.h
#pragma once
#include <vector>
#include "../data_classes/point.h"

std::vector<Point> read_csv(const std::string& file_path, bool skip_header = false);
void csv_write(const std::string& file_path, const std::vector<Point>& data, const std::vector<Point>& centroids);