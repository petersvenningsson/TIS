#include "Hypothesis.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(DensityTest, update) {
    Eigen::Vector3d prior;
    prior << PRIOR_POSITION, PRIOR_POSITION, PRIOR_POSITION;
    Density density(prior, SIGMA_VELOCITY);

    Eigen::Vector3d detection;
    detection << MEASURED_POSITION, MEASURED_POSITION, MEASURED_POSITION;
    Eigen::Matrix3d R;
    R << MEASURED_POSITION, 0.0, 0.0, 0.0, MEASURED_POSITION, 0.0, 0.0, 0.0,
        MEASURED_POSITION;
    density.update(detection, R);

    EXPECT_THAT(density.x()(0),
                testing::AllOf(testing::Ge(PRIOR_POSITION),
                               testing::Le(MEASURED_POSITION)));
}
