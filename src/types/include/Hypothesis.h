#pragma once

#include "Association.h"

/**
 * A class descring a hypothesis based on a single measurement.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Hypothesis {
   public:
    Hypothesis(const Association& association, const double& distance);
#ifndef UNIT_TEST
   private:
#endif
    Association association_;
    double distance_;
};
