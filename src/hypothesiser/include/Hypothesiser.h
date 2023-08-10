#pragma once

#include <chrono>
#include <vector>

#include "Detection.h"
#include "Hypothesis.h"
#include "Track.h"

/**
 * Class responsable creating track hypothesis.
 *
 */
class Hypothesiser {
   public:
    Hypothesiser(double missed_distance);

    std::vector<Hypothesis> hypothesise(
        const Track& track, std::vector<Detection> detections,
        std::chrono::time_point<std::chrono::steady_clock> timestamp);
#ifndef UNIT_TEST
   private:
#endif
    double missed_distance_;
};
