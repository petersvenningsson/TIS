#pragma once

#include <Eigen/Dense>

#include "tis/TransitionModel.h"

/**
 * A class which implements a constant velocity transition model.
 */
class ConstantVelocityTransitionModel : public TransitionModel {
   public:
    ConstantVelocityTransitionModel(double velocity_sigma);
    Eigen::Matrix<double, 6, 6> matrix(double dt) override;
    Eigen::Matrix<double, 6, 6> covariance(double dt) override;
    Eigen::Matrix<double, 6, 1> function(
        Eigen::Matrix<double, 6, 1> state_vector, double dt) override;

   private:
    double velocity_sigma_;
};
