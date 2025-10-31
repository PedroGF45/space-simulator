#pragma once

#include <vector>

class SpaceObject;

class IPhysicsModel {
public:
    virtual ~IPhysicsModel() = default;

    // Compute forces (or accelerations) for the provided objects and update their net force
    virtual void computeForces(std::vector<SpaceObject*>& objects) = 0;
};
