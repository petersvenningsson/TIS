#include "Track.h"

#include <chrono>

#include "Density.h"

Track::Track(const Density& density) : density_(density) {
}

Track::Track(const Detection& detection) : density_(detection.vector()) {
}
