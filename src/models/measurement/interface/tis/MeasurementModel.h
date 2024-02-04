#pragma once

#include <Eigen/Dense>

/**
 * A base class for a measurement model.
 */
class MeasurementModel {
   public:
    virtual Eigen::Matrix<double, 3, 6> matrix() = 0;
    virtual Eigen::Matrix<double, 3, 3> covariance() = 0;
    virtual Eigen::Matrix<double, 3, 1> function(
        Eigen::Matrix<double, 6, 1> state_vector) = 0;

    virtual ~MeasurementModel() {
    }
};
