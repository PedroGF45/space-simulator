#include "pch.h"

#include "../include/simulation/Vector3D.h"
#include "../include/simulation/SpaceObject.h"

// Helper tolerance for floating comparisons
static constexpr double EPS = 1e-9;

TEST(SpaceObjectTest, GettersSettersAndPhysics) {
    SpaceObject obj("Test", 10.0, Vector3D(0, 0, 0), Vector3D(1, 0, 0), Vector3D(0, 0, 0));

    EXPECT_EQ(obj.getName(), "Test");
    EXPECT_DOUBLE_EQ(obj.getMass(), 10.0);

    // set a net force and update acceleration
    obj.setNetForce(Vector3D(10.0, 0.0, 0.0)); // force = 10 N, mass = 10 kg => a = 1 m/s^2
    obj.updateAcceleration();
    EXPECT_NEAR(obj.getAcceleration().getX(), 1.0, EPS);
    EXPECT_NEAR(obj.getAcceleration().getY(), 0.0, EPS);
    EXPECT_NEAR(obj.getAcceleration().getZ(), 0.0, EPS);

    // update object with dt = 2s:
    // velocity = 1 + 1*2 = 3
    // position = 0 + 3*2 = 6  (updateObject uses updated velocity when computing position)
    obj.updateObject(2.0);
    EXPECT_NEAR(obj.getVelocity().getX(), 3.0, EPS);
    EXPECT_NEAR(obj.getPosition().getX(), 6.0, EPS);
}
