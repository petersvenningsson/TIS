#pragma once

#include <Eigen/Dense>

#include "tis/MeasurementModel.h"

/**
 * A class which implements a linear gaussian measurement model.
 */
class LinearGaussianMeasurementModel : MeasurementModel {
   public:
    LinearGaussianMeasurementModel(
        const Eigen::Matrix<double, 3, 3>& noise_covariance);

    Eigen::Matrix<double, 3, 6> matrix(void) override;
    Eigen::Matrix<double, 3, 3> covariance(void) override;
    Eigen::Matrix<double, 3, 1> function(
        Eigen::Matrix<double, 6, 1> state_vector) override;

   private:
    Eigen::Matrix<double, 3, 3> noise_covariance_;
    Eigen::Matrix<double, 3, 6> matrix_;
};
