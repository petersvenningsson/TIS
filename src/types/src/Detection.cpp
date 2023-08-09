#include "Detection.h"

Detection::Detection(Eigen::Matrix<double, 3, 1> vector) : vector_(vector) {
    timestamp_ = std::chrono::system_clock::now();
}

Detection::Detection(
    Eigen::Matrix<double, 3, 1> vector,
    std::chrono::time_point<std::chrono::system_clock> timestamp)
    : vector_(vector), timestamp_(timestamp) {
}
