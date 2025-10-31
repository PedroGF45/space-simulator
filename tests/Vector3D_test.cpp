#include "pch.h"

#include "../include/simulation/Vector3D.h"

// Helper tolerance for floating comparisons
static constexpr double EPS = 1e-9;

TEST(Vector3DTest, BasicOperations) {
    Vector3D a(1.0, 2.0, 3.0);
    Vector3D b(2.0, -1.0, 0.5);

    EXPECT_DOUBLE_EQ(a.getX(), 1.0);
    EXPECT_DOUBLE_EQ(a.getY(), 2.0);
    EXPECT_DOUBLE_EQ(a.getZ(), 3.0);

    Vector3D sum = a + b;
    EXPECT_DOUBLE_EQ(sum.getX(), 3.0);
    EXPECT_DOUBLE_EQ(sum.getY(), 1.0);
    EXPECT_DOUBLE_EQ(sum.getZ(), 3.5);

    Vector3D diff = a - b;
    EXPECT_DOUBLE_EQ(diff.getX(), -1.0);
    EXPECT_DOUBLE_EQ(diff.getY(), 3.0);
    EXPECT_DOUBLE_EQ(diff.getZ(), 2.5);

    Vector3D scaled = a * 2.0;
    EXPECT_DOUBLE_EQ(scaled.getX(), 2.0);
    EXPECT_DOUBLE_EQ(scaled.getY(), 4.0);
    EXPECT_DOUBLE_EQ(scaled.getZ(), 6.0);

    Vector3D divided = a / 2.0;
    EXPECT_DOUBLE_EQ(divided.getX(), 0.5);
    EXPECT_DOUBLE_EQ(divided.getY(), 1.0);
    EXPECT_DOUBLE_EQ(divided.getZ(), 1.5);

    double mag = a.getMagnitude();
    EXPECT_NEAR(mag, std::sqrt(1.0 + 4.0 + 9.0), EPS);
}
