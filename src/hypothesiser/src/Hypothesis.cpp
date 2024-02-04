#include "tis/Hypothesis.h"

Hypothesis::Hypothesis(const Track& track, const Detection& detection,
                       double weight)
    : track_(track),
      detection_(detection),
      weight_(weight),
      missed_detection_(false) {
}

Hypothesis::Hypothesis(const Track& track, double weight)
    : track_(track), weight_(weight), missed_detection_(true) {
}

bool Hypothesis::operator<(const Hypothesis& rhs) const {
    return weight_ < rhs.weight_;
}

bool Hypothesis::operator>(const Hypothesis& rhs) const {
    return weight_ > rhs.weight_;
}

bool Hypothesis::operator==(const Hypothesis& rhs) const {
    if (detection().has_value() && rhs.detection().has_value()) {
        return (track() == rhs.track() && detection() == rhs.detection());
    } else if (!detection().has_value() && !rhs.detection().has_value()) {
        return (track() == rhs.track());
    } else {
        return false;
    }
}

bool Hypothesis::operator!=(const Hypothesis& rhs) const {
    return !(*this == rhs);
}

double Hypothesis::weight(void) const {
    return weight_;
}

std::optional<Detection> Hypothesis::detection(void) const {
    return detection_;
}

Track Hypothesis::track(void) const {
    return track_;
}

bool Hypothesis::missed_detection(void) const {
    return missed_detection_;
}
