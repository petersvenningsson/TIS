#include "Hypothesiser.h"

#include <algorithm>

/*
 * for (const auto& elem : set_to_remove) {
    myset.erase(elem);
 }
 *
 *
 *
 * */

Hypothesiser::Hypothesiser(double missed_distance)
    : missed_distance_(missed_distance) {
}

/*
 * @param detections Detections used to generate hypotheses.
 * @param track The track which hypothesis will be generated for.
 * @returns Sets of possible hypotheses ordered best to worst.
 */
std::vector<Hypothesis> Hypothesiser::hypothesise(
    const Track& track, std::vector<Detection> detections,
    std::chrono::time_point<std::chrono::steady_clock> timestamp) {
    std::vector<Hypothesis> hypotheses;

    // Add missed detection hypothesis
    hypotheses.push_back(Hypothesis(track, missed_distance_));

    for (Detection detection : detections) {
        double distance =
            std::hypot(std::hypot(track.x()(0) - detection.vector()(0),
                                  track.x()(1) - detection.vector()(1)),
                       track.x()(2) - detection.vector()(2));

        if (distance < missed_distance_) {
            hypotheses.push_back(Hypothesis(track, detection, distance));
        }
    }

    std::sort(hypotheses.begin(), hypotheses.end());
    return hypotheses;
}
