#include "pch.h"

#include "../include/simulation/Vector3D.h"
#include "../include/simulation/SpaceObject.h"
#include "../include/physics/GravitySystem.h"

// Helper tolerance for floating comparisons
static constexpr double EPS = 1e-9;

TEST(GravitySystemTest, TwoBodyForces) {
    // two bodies on x axis separated by d
    double m1 = 5.0;
    double m2 = 7.0;
    double d = 4.0;

    SpaceObject a("A", m1, Vector3D(0,0,0), Vector3D(0,0,0), Vector3D(0,0,0));
    SpaceObject b("B", m2, Vector3D(d,0,0), Vector3D(0,0,0), Vector3D(0,0,0));

    std::vector<SpaceObject*> objects = { &a, &b };

    GravitySystem gs;
    gs.CalculateGravity(objects);

    const double G = 6.67430 * std::pow(10.0, -11);
    double expectedForceMag = G * (m1 * m2) / (d * d);

    // a should feel a positive force in +x direction (towards b)
    EXPECT_NEAR(a.getNetForce().getX(), expectedForceMag, expectedForceMag * 1e-6 + 1e-18);
    EXPECT_NEAR(a.getNetForce().getY(), 0.0, EPS);
    EXPECT_NEAR(a.getNetForce().getZ(), 0.0, EPS);

    // b should feel the opposite force
    EXPECT_NEAR(b.getNetForce().getX(), -expectedForceMag, expectedForceMag * 1e-6 + 1e-18);
    EXPECT_NEAR(b.getNetForce().getY(), 0.0, EPS);
    EXPECT_NEAR(b.getNetForce().getZ(), 0.0, EPS);
}
