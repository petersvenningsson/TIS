#include "Hypothesis.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#define PRIOR_POSITION (0.0)
#define SIGMA_VELOCITY (1.0)

#define EPSILON (1e-6)

TEST(HypothesisTest, comparison) {
    Eigen::Vector3d prior;
    prior << PRIOR_POSITION, PRIOR_POSITION, PRIOR_POSITION;
    Density density(prior, SIGMA_VELOCITY);
    Track track(density);

    Eigen::Matrix<double, 3, 1> vector_rhs(1.0, 1.0, 1.0);
    Detection detection_rhs(vector_rhs);
    Hypothesis hypothesis_rhs(track, detection_rhs, 1 / (1.0 + EPSILON));

    Eigen::Matrix<double, 3, 1> vector_lhs(PRIOR_POSITION, PRIOR_POSITION,
                                           PRIOR_POSITION);
    Detection detection_lhs(vector_lhs);
    Hypothesis hypothesis_lhs(track, detection_lhs, 0.0 / (1.0 + EPSILON));

    EXPECT_TRUE(hypothesis_lhs < hypothesis_rhs);
}
