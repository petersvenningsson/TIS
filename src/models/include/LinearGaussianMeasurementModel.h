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
    Eigen::Matrix<double, 3, 3> covariance(void);
#ifndef UNIT_TEST
   private:
#endif
    Eigen::Matrix<double, 3, 3> noise_covariance_;
    Eigen::Matrix<double, 3, 6> matrix_;
};
