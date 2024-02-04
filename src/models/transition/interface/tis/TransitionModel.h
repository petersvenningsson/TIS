#pragma once

#include <Eigen/Dense>

/**
 * A class which implements a constant velocity transition model.
 */
class TransitionModel {
   public:
    virtual Eigen::Matrix<double, 6, 6> matrix(double dt) = 0;
    virtual Eigen::Matrix<double, 6, 6> covariance(double dt) = 0;
    virtual Eigen::Matrix<double, 6, 1> function(
        Eigen::Matrix<double, 6, 1> state_vector, double dt) = 0;

    virtual ~TransitionModel() {
    }
};
