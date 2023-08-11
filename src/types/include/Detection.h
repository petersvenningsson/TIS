#pragma once

#include <Eigen/Dense>
#include <chrono>

/**
 * A class describing a 3d measurement.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Detection {
   public:
    Detection(Eigen::Matrix<double, 3, 1> vector);
    Detection(Eigen::Matrix<double, 3, 1> vector,
              std::chrono::time_point<std::chrono::system_clock> timestamp);
    Eigen::Matrix<double, 3, 1> vector() const;

    bool operator<(const Detection& rhs) const;
    bool operator>(const Detection& rhs) const;
    bool operator==(const Detection& rhs) const;

    size_t id(void) const;
#ifndef UNIT_TEST
   private:
#endif
    Eigen::Matrix<double, 3, 1> vector_;
    std::chrono::time_point<std::chrono::system_clock> timestamp_;

    static size_t id_count;
    size_t id_;
};
