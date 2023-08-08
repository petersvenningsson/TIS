#pragma once
#include <Eigen/Dense>

#include "Density.h"

/**
 * A class describing a target track.
 *
 * The class is composed of a density which describes a belief about the
 * position of an object represented by the mean x and the covariance matrix P.
 *
 * The class also has several member variables which can be used for track
 * management, when the track was last updated, how many times the track has
 * been updated and if the track is in a tentative state (or is a confirmed
 * track).
 *
 * The Track class is used by the Tracker class to represent a unique object
 * which is followed over time.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * Eigen::Vector3d prior;
 * prior << 1, 1, 1;
 * Track track(prior); // Initialize the track
 *
 * Eigen::Vector3d detection;
 * detection << 2, 1, 1;
 * track.update(detection); // Update the track with a detection
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Track {
   public:
    Track(Eigen::Vector3d detection, const double sigma_velocity);
    static double stampTime();
    void update(Eigen::Vector3d detection, Eigen::Matrix3d R);
    /**
     * @returns the mean of the track position.
     */
    Eigen::Matrix<double, 6, 1> x() {
        return density_.x();
    }
    /**
     * Get the timestamp of the last detetection associated to the track.
     *
     * The timestamp is a UNIX timestamp up to millisecond precision
     * represented as a double precision floating number.
     *
     * @returns timestamp of the last update time.
     */
    double lastUpdateTime() {
        return last_update_time_;
    }
    /**
     * @returns the number of detections associated to the track.
     */
    double numDetections() {
        return num_detections_;
    }
    /**
     * @returns if track is tentative.
     */
    bool tentative() {
        return tentative_;
    }
    /**
     * Method to set if the track is tentative or confirmed.
     *
     * @param tentative
     */
    void tentative(int t) {
        tentative_ = t;
    }

   private:
    Density density_;
    double last_update_time_;
    int num_detections_;
    bool tentative_;
};
