#include "JointHypothesis.h"

JointHypothesis::JointHypothesis(const std::vector<Hypothesis>& hypotheses)
    : hypotheses_(hypotheses), weight_(0) {
    for (auto hypothesis : hypotheses) {
        weight_ += hypothesis.weight();
    }
}

bool JointHypothesis::operator<(const Hypothesis& rhs) const {
    return weight_ < rhs.weight_;
}

bool JointHypothesis::operator>(const Hypothesis& rhs) const {
    return weight_ < rhs.weight_;
}
