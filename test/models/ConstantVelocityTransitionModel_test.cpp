#include "ConstantVelocityTransitionModel.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ConstantVelocityTransitionModelTest, matrix) {
    ConstantVelocityTransitionModel model(1.0);

    auto matrix = model.matrix(1.0);

    EXPECT_FLOAT_EQ(matrix(0, 3), 1.0);
}

TEST(ConstantVelocityTransitionModelTest, covariance) {
    ConstantVelocityTransitionModel model(1.0);

    auto cov = model.covariance(1.0);

    EXPECT_FLOAT_EQ(cov(5, 5), 1.0);
}
