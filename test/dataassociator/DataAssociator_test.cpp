#include "DataAssociator.h"

#include "gtest/gtest.h"

class DataAssociatorTest : public ::testing::Test {
   protected:
    Hypothesiser hypothesiser{0.5};
    DataAssociator dataAssociator{hypothesiser};
};

/*
TEST_F(DataAssociatorTest, TestEmptyTracksAndDetections) {
    std::vector<Track> tracks;
    std::vector<Detection> detections;

    auto result = dataAssociator.associate(tracks, detections,
                                           std::chrono::steady_clock::now());

    EXPECT_EQ(result, JointHypothesis{});
}
*/

TEST_F(DataAssociatorTest, JointHypothesisTrueDetection) {
    Eigen::Vector3d detection1_vec(1, 1, 1);
    Eigen::Vector3d detection2_vec(2, 2, 2);
    Eigen::Vector3d detection2_vec_pertubated(2.1, 2.1, 2.1);
    Detection detection1(detection1_vec);
    Detection detection2(detection2_vec);
    std::vector<Detection> detections{detection1, detection2};

    Density density1(detection1_vec);
    Density density2(detection2_vec_pertubated);
    Track track1(density1);
    Track track2(density2);
    std::vector<Track> tracks{track1, track2};

    JointHypothesis joint_hypothesis = dataAssociator.associate(
        tracks, detections, std::chrono::steady_clock::now());

    ASSERT_EQ(*(joint_hypothesis.hypotheses()[0].detection()), detection1);
    ASSERT_EQ(*(joint_hypothesis.hypotheses()[1].detection()), detection2);

    ASSERT_TRUE(joint_hypothesis.hypotheses().size() == 2);
}

TEST_F(DataAssociatorTest, JointHypotesisMissedDetection) {
    Eigen::Vector3d detection1_vec(100, 100, 100);
    Eigen::Vector3d track1_vec(1.0, 1.0, 1.0);
    Eigen::Vector3d track2_vec(0.0, 0.0, 0.0);
    Detection detection1(detection1_vec);
    std::vector<Detection> detections{detection1};

    Density density1(track1_vec);
    Density density2(track2_vec);
    Track track1(density1);
    Track track2(density2);
    std::vector<Track> tracks{track1, track2};

    JointHypothesis joint_hypothesis = dataAssociator.associate(
        tracks, detections, std::chrono::steady_clock::now());

    ASSERT_FALSE(joint_hypothesis.hypotheses()[0].detection().has_value());
    ASSERT_FALSE(joint_hypothesis.hypotheses()[1].detection().has_value());

    ASSERT_TRUE(joint_hypothesis.hypotheses()[0].missed_detection());
    ASSERT_TRUE(joint_hypothesis.hypotheses()[1].missed_detection());
}
