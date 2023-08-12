#include "JointHypothesis.h"

JointHypothesis::JointHypothesis(const std::vector<Hypothesis>& hypotheses)
    : hypotheses_(hypotheses), weight_(0) {
    std::sort(hypotheses_.rbegin(), hypotheses_.rend());

    for (auto hypothesis : hypotheses) {
        weight_ += hypothesis.weight();
    }
}

/**
 * A Joint hypothesis is valid iff two tracks are not associated to the same
 * detection.
 *
 * @returns true if the JointHypothesis is valid.
 */
bool JointHypothesis::isValid(void) const {
    std::vector<Detection> detections;
    for (auto hypothesis : hypotheses_) {
        std::optional<Detection> detection = hypothesis.detection();
        if (detection.has_value()) {
            detections.push_back(*detection);
        }
    }

    return CheckUniqueness(detections);
}

/**
 * Checks if the elements in the std::vector<Detections> are unique.
 *
 * @param detections A vector of detections.
 * @returns true if elements in detections are unique.
 */
bool JointHypothesis::CheckUniqueness(
    std::vector<Detection>& detections) const {
    std::sort(detections.begin(), detections.end());

    auto it = std::adjacent_find(detections.begin(), detections.end());
    if (it != detections.end()) {
        return false;
    } else {
        return true;
    }
}

bool JointHypothesis::operator<(const JointHypothesis& rhs) const {
    return weight() < rhs.weight();
}

bool JointHypothesis::operator>(const JointHypothesis& rhs) const {
    return weight() < rhs.weight();
}

bool JointHypothesis::operator==(const JointHypothesis& rhs) const {
    return weight() < rhs.weight();
}

double JointHypothesis::weight(void) const {
    return weight_;
}
