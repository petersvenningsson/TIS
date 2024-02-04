#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "tis/EkfUpdater.h"
#include "tis/LinearGaussianMeasurementModel.h"

TEST(EkfUpdatorTest, update) {
    Eigen::Matrix<double, 3, 3> measurement_covariance =
        Eigen::Matrix<double, 3, 3>::Identity();
    measurement_covariance = measurement_covariance * 0.00000001;
    LinearGaussianMeasurementModel model(measurement_covariance);
    EkfUpdater updater{model};

    Eigen::Matrix<double, 6, 1> prior_state_vector{0, 0, 0, 1, 1, 1};
    Eigen::Matrix<double, 6, 6> prior_covariance =
        Eigen::Matrix<double, 6, 6>::Identity();
    State prior{prior_state_vector, prior_covariance};

    Eigen::Matrix<double, 3, 1> detection_vector{5, 5, 5};

    auto detection = Detection(detection_vector);

    State posterior = updater.update(prior, detection);

    EXPECT_FLOAT_EQ(posterior.state_vector(0), 5.0);
}
