#pragma once

#include <Eigen/Dense>

#include "State.h"
#include "tis/TransitionModel.h"

/**
 * A class responsable for mapping a State from t to t+1
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class EkfPredictor {
   public:
    EkfPredictor(TransitionModel&);

    State predict(const State& prior, double dt);

   private:
    TransitionModel& transition_model_;
};
