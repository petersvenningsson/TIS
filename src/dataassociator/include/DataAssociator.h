#pragma once

#include <map>
#include <vector>

#include "Hypothesiser.h"
#include "JointHypothesis.h"

/**
 * Class responsable for associating detections to tracks.
 *
 */
class DataAssociator {
   public:
    DataAssociator(const Hypothesiser&);
    JointHypothesis associate(
        const std::map<size_t, Track>& tracks,
        const std::vector<Detection>& detections,
        const std::chrono::time_point<std::chrono::steady_clock>& timestamp);
#ifndef UNIT_TEST
   private:
#endif
    void recursiveCombine(const std::vector<std::vector<Hypothesis>>& input,
                          std::vector<JointHypothesis>& result,
                          std::vector<Hypothesis> current, size_t depth);
    std::vector<JointHypothesis> generateAllJointHypotheses(
        const std::vector<std::vector<Hypothesis>>& input);

    Hypothesiser hypothesiser_;
};
