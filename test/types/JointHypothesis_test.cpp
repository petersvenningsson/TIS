#include "JointHypothesis.h"

#include <gtest/gtest.h>

#include "Detection.h"
#include "Track.h"

TEST(JointHypothesisTest, ConstructorAndWeight) {
    Track track1{Detection(Eigen::Vector3d(1, 1, 1))};
    Track track2{Detection(Eigen::Vector3d(2, 2, 2))};
    Detection det1{Eigen::Vector3d(1, 1, 1)};
    Detection det2{Eigen::Vector3d(2, 2, 2)};

    Hypothesis hyp1{track1, det1, 0.9};
    Hypothesis hyp2{track2, det2, 0.8};

    std::vector<Hypothesis> hypotheses = {hyp1, hyp2};
    JointHypothesis jointHypo(hypotheses);

    EXPECT_NEAR(jointHypo.weight(), 1.7, 1e-6);
}

TEST(JointHypothesisTest, IsNotValid) {
    Eigen::Vector3d vec1{1.0, 2.0, 3.0};
    Eigen::Vector3d vec2{2.0, 1.0, 3.0};
    Track track1{Detection(vec1)};
    Track track2{Detection(vec2)};
    Detection detection{vec1};

    Hypothesis hypo1(track1, detection, 0.8);
    Hypothesis hypo2(track2, detection, 0.8);

    std::vector<Hypothesis> hypotheses;
    hypotheses.push_back(hypo1);
    hypotheses.push_back(hypo2);

    JointHypothesis jointHypo(hypotheses);
    bool isValid = jointHypo.isValid();
    ASSERT_FALSE(isValid);
}

TEST(JointHypothesisTest, IsNotValidTrack) {
    Eigen::Vector3d vec1{1.0, 2.0, 3.0};
    Eigen::Vector3d vec2{2.0, 1.0, 3.0};
    Track track1{Detection(vec1)};
    Detection detection1{vec1};
    Detection detection2{vec2};

    Hypothesis hypo1(track1, detection1, 0.8);
    Hypothesis hypo2(track1, detection2, 0.8);

    std::vector<Hypothesis> hypotheses;
    hypotheses.push_back(hypo1);
    hypotheses.push_back(hypo2);

    JointHypothesis jointHypo(hypotheses);
    bool isValid = jointHypo.isValid();
    ASSERT_FALSE(isValid);
}

TEST(JointHypothesisTest, IsValidDetection) {
    Eigen::Vector3d vec1{1.0, 2.0, 3.0};
    Eigen::Vector3d vec2{2.0, 1.0, 3.0};
    Track track1{Detection(vec1)};
    Track track2{Detection(vec2)};
    Detection detection1{vec1};
    Detection detection2{vec2};

    Hypothesis hypo1(track1, detection1, 0.8);
    Hypothesis hypo2(track2, detection2, 0.8);

    std::vector<Hypothesis> hypotheses;
    hypotheses.push_back(hypo1);
    hypotheses.push_back(hypo2);

    JointHypothesis jointHypo(hypotheses);
    bool isValid = jointHypo.isValid();
    ASSERT_TRUE(isValid);
}
