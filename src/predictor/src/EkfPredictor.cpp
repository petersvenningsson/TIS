#include "tis/EkfPredictor.h"

EkfPredictor::EkfPredictor(TransitionModel& transition_model)
    : transition_model_(transition_model) {
}

State EkfPredictor::predict(const State& prior, double dt) {
    State posterior = prior;
    posterior.state_vector =
        transition_model_.function(prior.state_vector, dt);

    auto H = transition_model_.matrix(dt);
    auto Q = transition_model_.covariance(dt);
    posterior.covariance = H * prior.covariance * H.transpose() + Q;

    return posterior;
}
