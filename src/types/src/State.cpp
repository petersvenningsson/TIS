#include "State.h"

State::State(Eigen::Matrix<double, 6, 1> state_vector,
             Eigen::Matrix<double, 6, 6> covariance)
    : state_vector_(state_vector), covariance_(covariance) {
}

Eigen::Matrix<double, 6, 1>& State::stateVector(void) {
    return state_vector_;
}

Eigen::Matrix<double, 6, 6>& State::covariance(void) {
    return covariance_;
}
