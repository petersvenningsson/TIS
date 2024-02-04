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
    Hypothesis(const Track& track, double weight);
    Hypothesis(const Track& track, const Detection& detection, double weight);

    double weight(void) const;
    bool operator<(const Hypothesis& rhs) const;
    bool operator>(const Hypothesis& rhs) const;
    bool operator==(const Hypothesis& rhs) const;
    bool operator!=(const Hypothesis& rhs) const;
    std::optional<Detection> detection(void) const;
    Track track(void) const;
    bool missed_detection(void) const;

   private:
    Track track_;
    std::optional<Detection> detection_;
    double weight_;
    bool missed_detection_;
};
