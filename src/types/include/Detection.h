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

   private:
    Eigen::Matrix<double, 3, 1> vector_;
    std::chrono::time_point<std::chrono::system_clock> timestamp_;
};
