#include "Hypothesis.h"

static const double epsilon(1e-6);

Hypothesis::Hypothesis(const Track& track, const Detection& detection,
                       const double& distance)
    : track_(track),
      detection_(detection),
      weight_(1 / (distance + epsilon)),
      missed_detection_(false) {
}

Hypothesis::Hypothesis(const Track& track, const double& distance)
    : track_(track),
      weight_(1 / (distance + epsilon)),
      missed_detection_(true) {
}

bool Hypothesis::operator<(const Hypothesis& rhs) const {
    return weight_ < rhs.weight_;
}

double Hypothesis::weight(void) const {
    return weight_;
}
