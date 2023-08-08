#include "Track.h"

#include <chrono>

#include "Density.h"

/**
 * Constructor which initializes a track from a 3D point.
 *
 * @param detection the initialization point for the new track.
 */
Track::Track(Eigen::Vector3d detection, const double sigma_velocity)
    : density_(detection, sigma_velocity), num_detections_(1), tentative_(1) {
    last_update_time_ = stampTime();
}

/**
 * @returns the current unix timestamp up to millisecond precision.
 */
double Track::stampTime() {
    return (double)std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::system_clock::now().time_since_epoch())
               .count() *
           1e-3;
}

/**
 * Method which updates the track with a measurement asuming
 * that measurement noise follow a normal distribution.
 *
 * @param detection the mean of the initialized density.
 * @param R the covariance matrix of the measurement noise.
 */
void Track::update(Eigen::Vector3d detection, Eigen::Matrix3d R) {
    density_.update(detection, R);
    last_update_time_ = stampTime();
    num_detections_++;
}
