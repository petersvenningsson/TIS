#include "tis/ConstantVelocityTransitionModel.h"

ConstantVelocityTransitionModel::ConstantVelocityTransitionModel(
    double velocity_sigma)
    : velocity_sigma_(velocity_sigma) {
}

Eigen::Matrix<double, 6, 6> ConstantVelocityTransitionModel::matrix(
    double dt) {
    Eigen::Matrix<double, 6, 6> matrix = Eigen::MatrixXd::Identity(6, 6);
    matrix(0, 3) = dt;
    matrix(1, 4) = dt;
    matrix(2, 5) = dt;
    return matrix;
}

Eigen::Matrix<double, 6, 1> ConstantVelocityTransitionModel::function(
    Eigen::Matrix<double, 6, 1> state_vector, double dt) {
    matrix(dt) * state_vector;
}

Eigen::Matrix<double, 6, 6> ConstantVelocityTransitionModel::covariance(
    double dt) {
    Eigen::Matrix<double, 6, 6> Q;
    Q << std::pow(dt, 4) / 4, 0.0, 0.0, std::pow(dt, 3) / 2, 0.0, 0.0, 0.0,
        std::pow(dt, 4) / 4, 0.0, 0.0, std::pow(dt, 3) / 2, 0.0, 0.0, 0.0,
        std::pow(dt, 4) / 4, 0.0, 0.0, std::pow(dt, 3) / 2,
        std::pow(dt, 3) / 2, 0.0, 0.0, std::pow(dt, 2), 0.0, 0.0, 0.0,
        std::pow(dt, 3) / 2, 0.0, 0.0, std::pow(dt, 2), 0.0, 0.0, 0.0,
        std::pow(dt, 3) / 2, 0.0, 0.0, std::pow(dt, 2);

    Q = Q * std::pow(velocity_sigma_, 2);
    return Q;
}
