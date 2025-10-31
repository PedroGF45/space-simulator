#pragma once

#include "IIntegrator.h"
#include <vector>

class SpaceObject;
class IPhysicsModel;

class VelocityVerlet : public IIntegrator {
public:
    VelocityVerlet(IPhysicsModel* model) : physics_model(model) {}

    void integrate(std::vector<SpaceObject*>& objects, double dt) override;

private:
    IPhysicsModel* physics_model; // used to recompute forces after position update
};
