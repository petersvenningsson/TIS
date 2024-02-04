#pragma once

#include <Eigen/Dense>

/**
 * A class which implements a constant velocity transition model.
 */
class ConstantVelocityTransitionModel {
   public:
    ConstantVelocityTransitionModel(double velocity_sigma);
    Eigen::Matrix<double, 6, 6> matrix(double dt);
    Eigen::Matrix<double, 6, 6> covariance(double dt);
    Eigen::Matrix<double, 6, 1> function(
        Eigen::Matrix<double, 6, 1> state_vector, double dt);

   private:
    double velocity_sigma_;
};
