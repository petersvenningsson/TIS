#include "tis/DataAssociator.h"

namespace tis {

DataAssociator::DataAssociator(const Hypothesiser& hypothesiser)
    : hypothesiser_(hypothesiser) {
}

/* Make this a template function for any container */
tis::JointHypothesis DataAssociator::associate(
    const std::map<size_t, Track>& tracks,
    const std::vector<Detection>& detections,
    const std::chrono::time_point<std::chrono::steady_clock>& timestamp) {
    /* for each track generate its hypotheses */
    std::vector<std::vector<Hypothesis>> hypotheses_by_track;
    for (auto [unused, track] : tracks) {
        auto hypotheses =
            hypothesiser_.hypothesise(track, detections, timestamp);
        hypotheses_by_track.push_back(hypotheses);
    }

    /* generate all valid joint hypotheses */
    std::vector<tis::JointHypothesis> all_joint_hypotheses =
        generateAllJointHypotheses(hypotheses_by_track);

    std::sort(all_joint_hypotheses.rbegin(), all_joint_hypotheses.rend());

    all_joint_hypotheses.erase(
        std::remove_if(
            all_joint_hypotheses.begin(), all_joint_hypotheses.end(),
            [](const tis::JointHypothesis& obj) { return !obj.isValid(); }),
        all_joint_hypotheses.end());

    return all_joint_hypotheses.at(0);
}

void DataAssociator::recursiveCombine(
    const std::vector<std::vector<Hypothesis>>& input,
    std::vector<tis::JointHypothesis>& result, std::vector<Hypothesis> current,
    size_t depth) {
    if (depth == input.size()) {
        result.push_back(tis::JointHypothesis(current));
        return;
    }

    for (size_t i = 0; i < input[depth].size(); ++i) {
        std::vector<Hypothesis> newCurrent = current;
        newCurrent.push_back(input[depth][i]);
        recursiveCombine(input, result, newCurrent, depth + 1);
    }
}

std::vector<tis::JointHypothesis> DataAssociator::generateAllJointHypotheses(
    const std::vector<std::vector<Hypothesis>>& input) {
    std::vector<tis::JointHypothesis> result;
    recursiveCombine(input, result, {}, 0);
    return result;
}

}  // namespace tis
