#include "LinearGaussianMeasurementModel.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(LinearGaussianMeasurementModelTest, matrix) {
    Eigen::Matrix<double, 3, 3> noise_covariance =
        Eigen::MatrixXd::Identity(3, 3);
    LinearGaussianMeasurementModel model(noise_covariance);

    auto matrix = model.matrix();
    EXPECT_FLOAT_EQ(matrix(0, 0), 1.0);
}

TEST(LinearGaussianMeasurementModelTest, covariance) {
    Eigen::Matrix<double, 3, 3> noise_covariance =
        Eigen::MatrixXd::Identity(3, 3);

    LinearGaussianMeasurementModel model(noise_covariance);
    auto cov = model.covariance();
    EXPECT_FLOAT_EQ(cov(0, 0), noise_covariance(0, 0));
}
