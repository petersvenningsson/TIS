#pragma once

#include <chrono>
#include <vector>

#include "Detection.h"
#include "Track.h"
#include "tis/Hypothesis.h"

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

   private:
    double missed_distance_;
};
