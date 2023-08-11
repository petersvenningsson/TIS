#include "Detection.h"

Detection::Detection(Eigen::Matrix<double, 3, 1> vector) : vector_(vector) {
    timestamp_ = std::chrono::system_clock::now();
}

Detection::Detection(
    Eigen::Matrix<double, 3, 1> vector,
    std::chrono::time_point<std::chrono::system_clock> timestamp)
    : vector_(vector), timestamp_(timestamp) {
}

Eigen::Matrix<double, 3, 1> Detection::vector() const {
    return vector_;
}

bool Detection::operator<(const Point &o) const {
    if (x != o.x) {
        return x < o.x;
    }
    if (y != o.y) {
        return y < o.y;
    }
    return z < o.z;
}
