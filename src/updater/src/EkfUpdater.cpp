#include "tis/EkfUpdater.h"

#include <iostream>

EkfUpdater::EkfUpdater(MeasurementModel& measurement_model)
    : measurement_model_(measurement_model) {
}

State EkfUpdater::update(const State& prior, const Detection& detection) {
    State posterior = prior;

    auto H = measurement_model_.matrix();

    auto S = (H * prior.covariance) * H.transpose() +
             measurement_model_.covariance();

    auto K = ((prior.covariance * H.transpose()) * S.inverse()).eval();

    posterior.state_vector =
        prior.state_vector +
        K * (detection.vector() -
             measurement_model_.function(prior.state_vector));

    posterior.covariance = prior.covariance - K * H * prior.covariance;

    return posterior;
}
