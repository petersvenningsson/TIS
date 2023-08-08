#include "LinearGaussianMeasurementModel.h"

LinearGaussianMeasurementModel::LinearGaussianMeasurementModel(
    const Eigen::Matrix<double, 3, 3>& noise_covariance)
    : noise_covariance_(noise_covariance) {
    matrix_ = Eigen::MatrixXd::Zero(3, 6);
    matrix_(0, 0) = 1;
    matrix_(1, 1) = 1;
    matrix_(2, 2) = 1;
}

Eigen::Matrix<double, 3, 6> LinearGaussianMeasurementModel::matrix(void) {
    return matrix_;
}

Eigen::Matrix<double, 3, 3> LinearGaussianMeasurementModel::covariance(void) {
    return noise_covariance_;
}
