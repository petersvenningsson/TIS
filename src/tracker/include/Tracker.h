#pragma once

#include <Eigen/Dense>
#include <map>
#include <vector>

#include "Density.h"
#include "tis/DataAssociator.h"

/**
 * A class describing a Kalman based single hypothesis mulit-object tracker.
 *
 * The class describes a Kalman based multi-object tracker capable of tracking
 * stationary objects. The tracker uses a reciprical data association scheme.
 *
 * Tentative tracks are confirmed when they are detected more than
 * *confirmation_threshold* times. Tentative tracks are removed if they have
 * not been detected in the last *age_threshold* seconds.
 *
 * It is trivial to extend the Tracker class to track dynamic objects by
 * implementing a meaningful predict method in the Track class.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * Tracker tracker;
 *
 * std::vector<Eigen::Vector2d> detections;
 * Eigen::Vector2d detection;
 * detection << 1, 1;
 * detections.push_back(detection);
 * detection << 2, 2;
 * detections.push_back(detection);
 *
 * tracker.update(detections);
 * std::vector<Track> tracks = tracker.tracks();
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Tracker {
   public:
    Tracker();
    void update(const std::vector<Detection>& detections);

   private:
    tis::DataAssociator data_associator_;
    void groomTracks();
    void confirmTracks();
    void initializeTrack(Eigen::Vector3d detection);
    std::map<size_t, Track> tracks_;
    double association_threshold_;
    double age_threshold_;
    int confirmation_threshold_;
};
