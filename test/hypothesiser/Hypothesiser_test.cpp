#include "Hypothesiser.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#define PRIOR_POSITION (0.0)
#define SIGMA_VELOCITY (1.0)
#define MISSED_DISTANCE (5.0)

TEST(HypothesiserTest, comparison) {
    Eigen::Matrix<double, 3, 1> vector_rhs(1.0, 1.0, 1.0);
    Detection detection_rhs(vector_rhs);
    Eigen::Matrix<double, 3, 1> vector_lhs(PRIOR_POSITION, PRIOR_POSITION,
                                           PRIOR_POSITION);
    Detection detection_lhs(vector_lhs);
    std::vector<Detection> detections;
    detections.push_back(detection_rhs);
    detections.push_back(detection_lhs);

    Eigen::Vector3d prior;
    prior << PRIOR_POSITION, PRIOR_POSITION, PRIOR_POSITION;
    Density density(prior, SIGMA_VELOCITY);
    Track track(density);

    Hypothesiser hypothesiser(MISSED_DISTANCE);

    std::vector<Hypothesis> hypotheses = hypothesiser.hypothesise(
        track, detections, std::chrono::steady_clock::now());

    EXPECT_TRUE(hypotheses[0] > hypotheses[1]);
}
