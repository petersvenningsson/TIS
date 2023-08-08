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
#ifndef UNIT_TEST
   private:
#endif
    double velocity_sigma_;
};
