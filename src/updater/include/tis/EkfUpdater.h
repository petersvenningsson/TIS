#pragma once

#include <Eigen/Dense>

#include "Detection.h"
#include "State.h"
#include "tis/MeasurementModel.h"

/**
 * Class responsable for updating a track given a measurement.
 *
 */
class EkfUpdater {
   public:
    EkfUpdater(MeasurementModel&);

    State update(const State& prior, const Detection& detection);

   private:
    MeasurementModel& measurement_model_;
};
