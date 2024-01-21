#include "Tracker.h"

#include <algorithm>

#include "tis/JointHypothesis.h"

constexpr static double ASSOCIATION_DISANCE = (1.0);

/**
 * Default constructor using default settings.
 */
Tracker::Tracker() : data_associator_(ASSOCIATION_DISANCE) {
    association_threshold_ = 1.0;
    confirmation_threshold_ = 50;
    age_threshold_ = 0.5;
}

/**
 * Method to create a new track initialized from a detection.
 *
 * @param detection the position of the initialized track.
 */
void Tracker::initializeTrack(Eigen::Vector3d detection) {
    /*tracks_.push_back(Track(detection));*/
}

/**
 * Method to update the tracks with new object detections.
 *
 * @param detections a vector of new object detections.
 */
void Tracker::update(const std::vector<Detection>& detections) {
    /*
        if (tracks_.size() == 0) {
            for (auto detection : detections)
                initializeTrack(detection);
            return;
        }
    */
    /*
    if (detections.size() == 0) {
        groomTracks();
        return;
    }
    */

    auto timestamp = std::chrono::steady_clock::now();
    tis::JointHypothesis joint_hypothesis =
        data_associator_.associate(tracks_, detections, timestamp);

    /* update associated tracks with associated detections */
    for (Hypothesis hypothesis : joint_hypothesis.hypotheses()) {
        auto iter = tracks_.find(hypothesis.track().id());
        if (iter != tracks_.end() && hypothesis.detection().has_value()) {
            iter->second.update(*(hypothesis.detection()));
        }
    }
    /* initialize tracks from unused detections
    std::sort(used_indices.begin(), used_indices.end(),
              std::greater<int>());
    for (int i : used_indices) {
        detections.erase(detections.begin() + i);
    }
    for (auto detection : detections) {
        initializeTrack(detection);
    }

    groomTracks();
    confirmTracks();
*/
}

/**
 * Method to delete tentative tracks which are only sporadically updated.
 *
 * This method is used internally by Tracker::update.
 */
void Tracker::groomTracks() {
    /*
    double time = Track::stampTime();
    std::vector<Track>::iterator it;
    for (it = tracks_.begin(); it != tracks_.end();) {
        if (it->tentative() &&
            std::abs(time - it->lastUpdateTime()) > age_threshold_)
            it = tracks_.erase(it);
        else
            ++it;
    }
*/
}

/**
 * Method to confirm tentative tracks if they have recieved a sufficient
 * number of detections.
 *
 * This method is used internally by Tracker::update.
 */
void Tracker::confirmTracks() {
    /*
    std::vector<Track>::iterator it;
    for (it = tracks_.begin(); it != tracks_.end(); it++) {
        if (it->tentative() && it->numDetections() > confirmation_threshold_)
            it->tentative(0);
    }
*/
}
