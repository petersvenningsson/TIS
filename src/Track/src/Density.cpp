#include <chrono>
#include "Density.h"

/**
 * Constructor which initializes a density from a 3D point.
 *
 * A density must be initialized from a 3D point.
 */
Density::Density(Eigen::Vector3d detection)
{
	x_ = detection;
	P_ << 10, 0,
	      0, 10;
}

/**
 * Method which updates the distribution with a measurement asuming
 * that measurement noise follow a normal distribution.
 *
 * @param detection the position of the measurement
 * @param R the covariance matrix of the measurement uncertaincy
 *
 * Notation follows https://en.wikipedia.org/wiki/Kalman_filter
 */
void Density::update(Eigen::Vector3d detection, Eigen::Matrix3d R)
{
	Eigen::Matrix3d S = P_ + R;
	Eigen::Matrix3d K = P_ * S.inverse();
	x_  = x_ + K * (detection - x_);
	P_ = P_ + (Eigen::MatrixXd::Identity(3,3) - K) * P_;
}

