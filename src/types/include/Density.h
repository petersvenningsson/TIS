#pragma once

#include <Eigen/Dense>

/**
 * A class describing a bi-variate normal distribution density.
 *
 * The class describes a bi-variate normal distribution. It can
 * be used to model the 3D-positional state of a object.
 * The mean vector can be used to describe the position of the object
 * and the covariance matrix P can be used to describe the uncertancy
 * of the object's position.
 *
 * The Density class is used by the Track class to represent the position of
 * a track.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * Eigen::Vector3d prior;
 * prior << 1, 1;
 * sigma_velocity = 1.0;
 * Density density(prior, sigma_velocity); // Initialize the density
 *
 * Eigen::Vector3d detection;
 * detection << 3, 1;
 *	Eigen::Matrix3d R;
 * 	R << 1.0, 0.0, 0.0,
 * 	     0.0, 0.0, 0.0,
 *		 0.0, 0.0, 1.0;
 * density.update(detection, R); // Update the density with a detection
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Density {
   public:
    Density(const Eigen::Vector3d&);
    Density(const Eigen::Vector3d&, const double&);
    void update(Eigen::Vector3d detection, Eigen::Matrix3d R);
    void predict(double dt);
    Eigen::Matrix<double, 6, 1> x() const {
        return x_;
    }
    Eigen::Matrix<double, 6, 6> P() const {
        return P_;
    }

#ifndef UNIT_TEST
   private:
#endif
    Eigen::Matrix<double, 6, 1> x_;
    Eigen::Matrix<double, 6, 6> P_;
    double sigma_velocity_;
};
