#!/bin/bash

# g++ -std=c++17 -o kmeans \
#   main.cpp \
#   data_classes/point.cpp \
#   utils/csv_utils.cpp \
#   algorithms/serial/lloyd_kmeans.cpp \
#   initializations/serial/random_initialization.cpp \
#   initializations/serial/kmeans_plusplus_initialization.cpp \
#   assignments/serial/basic_assign_clusters.cpp \
#   updates/serial/basic_update.cpp \
#   -Wall -Wextra -O2

#!/bin/bash

g++ -std=c++17 -o kmeans \
  main.cpp \
  data_classes/point.cpp \
  utils/csv_utils.cpp \
  abstract_classes/kmeans.cpp \
  algorithms/serial/lloyd_kmeans.cpp \
  initializations/serial/random_initialization.cpp \
  initializations/serial/kmeans_plusplus_initialization.cpp \
  assignments/serial/basic_assign_clusters.cpp \
  updates/serial/basic_update.cpp \
  -Wall -Wextra -O2
