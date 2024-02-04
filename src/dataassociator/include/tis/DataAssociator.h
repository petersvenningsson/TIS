#pragma once

#include <map>
#include <vector>

#include "tis/Hypothesiser.h"
#include "tis/JointHypothesis.h"

namespace tis {

/**
 * Class responsable for associating detections to tracks.
 *
 */
class DataAssociator {
   public:
    DataAssociator(const Hypothesiser&);
    tis::JointHypothesis associate(
        const std::map<size_t, Track>& tracks,
        const std::vector<Detection>& detections,
        const std::chrono::time_point<std::chrono::steady_clock>& timestamp);

   private:
    void recursiveCombine(const std::vector<std::vector<Hypothesis>>& input,
                          std::vector<tis::JointHypothesis>& result,
                          std::vector<Hypothesis> current, size_t depth);
    std::vector<tis::JointHypothesis> generateAllJointHypotheses(
        const std::vector<std::vector<Hypothesis>>& input);

    Hypothesiser hypothesiser_;
};

}  // namespace tis
