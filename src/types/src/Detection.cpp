#include "Detection.h"

size_t Detection::id_count = 0;

Detection::Detection(Eigen::Matrix<double, 3, 1> vector)
    : vector_(vector), id_(Detection::id_count++) {
    timestamp_ = std::chrono::system_clock::now();
}

Detection::Detection(
    Eigen::Matrix<double, 3, 1> vector,
    std::chrono::time_point<std::chrono::system_clock> timestamp)
    : vector_(vector), timestamp_(timestamp), id_(Detection::id_count++) {
}

Eigen::Matrix<double, 3, 1> Detection::vector() const {
    return vector_;
}

size_t Detection::id(void) const {
    return id_;
}

bool Detection::operator<(const Detection& rhs) const {
    return id_ < rhs.id();
}

bool Detection::operator>(const Detection& rhs) const {
    return id_ > rhs.id();
}

bool Detection::operator==(const Detection& rhs) const {
    return id_ == rhs.id();
}
