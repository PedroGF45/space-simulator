#include "pch.h"

#include "../include/simulation/Vector3D.h"
#include "../include/simulation/SpaceObject.h"
#include "../include/simulation/SimulationEngine.h"

TEST(SimulationEngineTest, UpdateSimulationAdvancesObjects) {
    double m1 = 5.0;
    double m2 = 7.0;
    double d = 4.0;

    SpaceObject a("A", m1, Vector3D(0,0,0), Vector3D(0,0,0), Vector3D(0,0,0));
    SpaceObject b("B", m2, Vector3D(d,0,0), Vector3D(0,0,0), Vector3D(0,0,0));

    std::vector<SpaceObject*> objects = { &a, &b };

    SimulationEngine engine(objects);

    Vector3D a_initial_pos = a.getPosition();
    Vector3D b_initial_pos = b.getPosition();

    double dt = 1.0; // 1 second

    engine.updateSimulation(dt);

    // After one update, net forces and accelerations must be set, and positions should change
    EXPECT_FALSE(a.getNetForce().getX() == 0.0 && a.getNetForce().getY() == 0.0 && a.getNetForce().getZ() == 0.0);
    EXPECT_FALSE(b.getNetForce().getX() == 0.0 && b.getNetForce().getY() == 0.0 && b.getNetForce().getZ() == 0.0);

    EXPECT_FALSE(a.getPosition().getX() == a_initial_pos.getX() && a.getPosition().getY() == a_initial_pos.getY() && a.getPosition().getZ() == a_initial_pos.getZ());
    EXPECT_FALSE(b.getPosition().getX() == b_initial_pos.getX() && b.getPosition().getY() == b_initial_pos.getY() && b.getPosition().getZ() == b_initial_pos.getZ());
}
