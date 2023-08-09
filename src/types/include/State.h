#pragma once

#include <Eigen/Dense>

/**
 * A class descring a state representation.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class State {
   public:
    State(Eigen::Matrix<double, 6, 1> state_vector,
          Eigen::Matrix<double, 6, 6> covariance);

    Eigen::Matrix<double, 6, 1>& stateVector(void);
    Eigen::Matrix<double, 6, 6>& covariance(void);
#ifndef UNIT_TEST
   private:
#endif
    Eigen::Matrix<double, 6, 1>& state_vector_;
    Eigen::Matrix<double, 6, 6>& covariance_;
};
