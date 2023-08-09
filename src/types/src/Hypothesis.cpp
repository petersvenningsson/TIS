#include "Hypothesis.h"

Hypothesis::Hypothesis(const Track& track, const Detection& detection,
                       const double& distance)
    : track_(track),
      detection_(detection),
      distance_(distance),
      missed_detection_(false) {
}

Hypothesis::Hypothesis(const Track& track, const double& distance)
    : track_(track), distance_(distance), missed_detection_(true) {
}

bool Hypothesis::operator<(const Hypothesis& rhs) const {
    return distance_ < rhs.distance_;
}
