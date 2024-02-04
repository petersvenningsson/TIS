#include "State.h"

State::State(Eigen::Matrix<double, 6, 1> state_vector,
             Eigen::Matrix<double, 6, 6> covariance)
    : state_vector(state_vector), covariance(covariance) {
}
