#pragma once

#include <vector>

class SpaceObject;

class IIntegrator {
public:
    virtual ~IIntegrator() = default;

    // Advance the simulation state by dt. The physics model should have already computed forces/accelerations.
    virtual void integrate(std::vector<SpaceObject*>& objects, double dt) = 0;
};
