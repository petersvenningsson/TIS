#pragma once

#include <optional>

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

    bool operator<(const Hypothesis& rhs) const;

#ifndef UNIT_TEST
   private:
#endif
    Track track_;
    std::optional<Detection> detection_;
    double distance_;
    bool missed_detection_;
};
