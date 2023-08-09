#pragma once

#include "Detection.h"
#include "Track.h"

/**
 * A class descring a hypothesis based on a single measurement.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Hypothesis {
   public:
    Hypothesis(const Track& track, const double& distance);
    Hypothesis(const Track& track, const Detection& detection,
               const double& distance);
#ifndef UNIT_TEST
   private:
#endif
    Track track_;
    Detection detection_;
    double distance_;
    bool missedDetection_;
};
