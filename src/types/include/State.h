#pragma once

#include <Eigen/Dense>

/**
 * A class descring a state representation.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
struct State {
   public:
    State(Eigen::Matrix<double, 6, 1> state_vector,
          Eigen::Matrix<double, 6, 6> covariance);

    Eigen::Matrix<double, 6, 1> state_vector;
    Eigen::Matrix<double, 6, 6> covariance;
};
