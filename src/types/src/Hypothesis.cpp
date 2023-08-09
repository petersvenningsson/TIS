#include "Hypothesis.h"

Hypothesis::Hypothesis(const Track& track, const Detection& detection,
                       const double& distance)
    : track_(track),
      detection_(detection),
      distance_(distance),
      missedDetection_(false) {
}

Hypothesis::Hypothesis(const Track& track, const double& distance)
    : track_(track), distance_(distance), missedDetection_(true) {
}
