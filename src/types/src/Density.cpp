#include "Density.h"

#include <chrono>

/**
 * Temporary constructor with default sigma_variance
 *
 * @param detection track initialization point
 */
Density::Density(const Eigen::Vector3d& detection) : sigma_velocity_{1.0} {
    x_ << detection(0), detection(1), detection(2), 0, 0, 0;
    P_ = Eigen::MatrixXd::Identity(6, 6);
    P_ = P_ * 10;
}

/**
 * Constructor which initializes a density from a 3D point.
 *
 * A density must be initialized from a 3D point.
 *
 * @param detection track initialization point
 * @param sigma_velocity_ the velocity covariance
 */
Density::Density(const Eigen::Vector3d& detection,
                 const double& sigma_velocity)
    : sigma_velocity_{sigma_velocity} {
    x_ << detection(0), detection(1), detection(2), 0, 0, 0;
    P_ = Eigen::MatrixXd::Identity(6, 6);
    P_ = P_ * 10;
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
void Density::update(Eigen::Vector3d detection, Eigen::Matrix3d R) {
    Eigen::Matrix<double, 3, 6> H = Eigen::MatrixXd::Zero(3, 6);
    H(0, 0) = 1;
    H(1, 1) = 1;
    H(2, 2) = 1;

    Eigen::Matrix<double, 3, 3> S = H * P_ * H.transpose() + R;
    Eigen::Matrix<double, 6, 3> K = (P_ * H.transpose()) * S.inverse();
    x_ = x_ + K * (detection - H * x_);
    P_ = (Eigen::MatrixXd::Identity(6, 6) - K * H) * P_;
}

/**
 * Method which maps the density from t to t+1 using a constant velocity
 * dynamical model.
 *
 * @param dt time delta between t and t+1
 *
 */
void Density::predict(double dt) {
    Eigen::Matrix<double, 6, 6> F = Eigen::MatrixXd::Identity(6, 6);
    F(0, 3) = dt;
    F(1, 4) = dt;
    F(2, 5) = dt;

    Eigen::Matrix<double, 6, 6> Q;
    Q << std::pow(dt, 4) / 4, 0.0, 0.0, std::pow(dt, 3) / 2, 0.0, 0.0, 0.0,
        std::pow(dt, 4) / 4, 0.0, 0.0, std::pow(dt, 3) / 2, 0.0, 0.0, 0.0,
        std::pow(dt, 4) / 4, 0.0, 0.0, std::pow(dt, 3) / 2,
        std::pow(dt, 3) / 2, 0.0, 0.0, std::pow(dt, 2), 0.0, 0.0, 0.0,
        std::pow(dt, 3) / 2, 0.0, 0.0, std::pow(dt, 2), 0.0, 0.0, 0.0,
        std::pow(dt, 3) / 2, 0.0, 0.0, std::pow(dt, 2);

    Q = Q * std::pow(sigma_velocity_, 2);

    auto f = F * x_;
    x_ = f;
    P_ = F * P_ * F.transpose() + Q;
}
