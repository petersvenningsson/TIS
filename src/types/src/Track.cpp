#include "Track.h"

#include <chrono>

#include "Density.h"

Track::Track(const Density& density) : density_(density) {
}

Track::Track(const Detection& detection) : density_(detection.vector()) {
}

void Track::update(const Detection& detection) {
    density_.update(detection);
}

Eigen::Matrix<double, 6, 1> Track::x() const {
    return density_.x();
}

Eigen::Matrix<double, 6, 6> Track::P() const {
    return density_.P();
}
