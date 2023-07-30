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
 * Density density(prior); // Initialize the density
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
class Density
{
	public:
		Density(Eigen::Vector3d);
		void update(Eigen::Vector3d detection, Eigen::Matrix3d R);
		/**
		 * Method which maps the distribtion of t to t+1 using a process model.
		 *
		 * @param detection a measurement of the density.
		 * @param R the covariance matrix of the measurement noise.
		 */
		void predict(double Ts) {}
		/**
		 * @returns the mean of the distribution
		 */
		Eigen::Vector3d x() {return x_;}
		/**
		 * @returns the covariance of the distribution
		 */
		Eigen::Matrix3d P() {return P_;}
	private:
		Eigen::Vector3d x_;
		Eigen::Matrix3d P_;
};

