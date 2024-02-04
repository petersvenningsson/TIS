#include "tis/EkfPredictor.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "tis/ConstantVelocityTransitionModel.h"

TEST(EkfPredictorTest, predict) {
    ConstantVelocityTransitionModel model(1.0);

    Eigen::Matrix<double, 6, 1> prior_state_vector{0, 0, 0, 1, 1, 1};
    Eigen::Matrix<double, 6, 6> prior_covariance =
        Eigen::Matrix<double, 6, 6>::Identity();
    State prior{prior_state_vector, prior_covariance};

    EkfPredictor predictor{model};

    constexpr double dt = 1.0;
    State posterior = predictor.predict(prior, dt);

    EXPECT_FLOAT_EQ(posterior.state_vector(0), 1.0);
}
