#include "Detection.h"

#include <gtest/gtest.h>

class DetectionTest : public ::testing::Test {
   protected:
    void SetUp() override {
        Detection::id_count = 0;
    }
};

TEST_F(DetectionTest, ConstructorTest) {
    Eigen::Matrix<double, 3, 1> vector(1.0, 2.0, 3.0);
    Detection d(vector);

    EXPECT_EQ(d.vector()(0), 1.0);
    EXPECT_EQ(d.vector()(1), 2.0);
    EXPECT_EQ(d.vector()(2), 3.0);

    EXPECT_EQ(d.id(), 0);
}

TEST_F(DetectionTest, IdIncrementTest) {
    Eigen::Matrix<double, 3, 1> vector(1.0, 2.0, 3.0);
    Detection d1(vector);
    Detection d2(vector);

    EXPECT_EQ(d1.id(), 0);
    EXPECT_EQ(d2.id(), 1);
}

TEST_F(DetectionTest, VectorSortingTest) {
    Eigen::Matrix<double, 3, 1> vector1(1.0, 2.0, 3.0);
    Eigen::Matrix<double, 3, 1> vector2(4.0, 5.0, 6.0);
    Eigen::Matrix<double, 3, 1> vector3(7.0, 8.0, 9.0);

    Detection d3(vector3);
    Detection d1(vector1);
    Detection d2(vector2);

    std::vector<Detection> detections = {d3, d1, d2};

    std::sort(detections.begin(), detections.end());

    EXPECT_EQ(detections[0].id(), 0);
    EXPECT_EQ(detections[1].id(), 1);
    EXPECT_EQ(detections[2].id(), 2);
}
