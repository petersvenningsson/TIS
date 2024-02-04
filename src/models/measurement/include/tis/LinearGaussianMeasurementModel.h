#pragma once

#include <Eigen/Dense>

/**
 * A class which implements a linear gaussian measurement model.
 */
class LinearGaussianMeasurementModel {
   public:
    LinearGaussianMeasurementModel(
        const Eigen::Matrix<double, 3, 3>& noise_covariance);
    Eigen::Matrix<double, 3, 6> matrix(void);
    Eigen::Matrix<double, 3, 1> function(
        Eigen::Matrix<double, 6, 1> state_vector);
    Eigen::Matrix<double, 3, 3> covariance(void);

   private:
    Eigen::Matrix<double, 3, 3> noise_covariance_;
    Eigen::Matrix<double, 3, 6> matrix_;
};
