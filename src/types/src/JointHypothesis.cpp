#include "JointHypothesis.h"

#include "UniqueId.h"

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
    std::vector<Track> tracks;
    for (auto hypothesis : hypotheses_) {
        std::optional<Detection> detection = hypothesis.detection();
        if (detection.has_value()) {
            detections.push_back(*detection);
        }
        tracks.push_back(hypothesis.track());
    }

    return (UniqueId::CheckUniqueness(detections) &&
            UniqueId::CheckUniqueness(tracks));
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

std::vector<Hypothesis> JointHypothesis::hypotheses(void) const {
    return hypotheses_;
}

bool JointHypothesis::operator<(const JointHypothesis& rhs) const {
    return weight() < rhs.weight();
}

bool JointHypothesis::operator>(const JointHypothesis& rhs) const {
    return weight() > rhs.weight();
}

bool JointHypothesis::operator==(const JointHypothesis& rhs) const {
    if (hypotheses().size() == rhs.hypotheses().size()) {
        for (size_t i = 0; i < hypotheses().size(); i++) {
            if (hypotheses()[i] != rhs.hypotheses()[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

double JointHypothesis::weight(void) const {
    return weight_;
}
