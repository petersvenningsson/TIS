#include "Density.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#define PRIOR_POSITION 0.0
#define PRIOR_VELOCITY 1.0
#define MEASURED_POSITION 1.0
#define SIGMA_VELOCITY 1.0
#define TIME_DELTA 1.0

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

TEST(DensityTest, predict) {
    Eigen::Vector3d prior;
    prior << PRIOR_POSITION, PRIOR_POSITION, PRIOR_POSITION;

    Density density(prior, SIGMA_VELOCITY);
    density.x_(3) = 1.0;

    Eigen::Vector3d detection;
    density.predict(TIME_DELTA);

    EXPECT_FLOAT_EQ(density.x()(0), PRIOR_VELOCITY * TIME_DELTA);
}
