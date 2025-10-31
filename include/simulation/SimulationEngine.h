#pragma once

#include <vector>
#include "SpaceObject.h"
#include <physics/GravitySystem.h>
#include <physics/IPhysicsModel.h>
#include <physics/IIntegrator.h>

class SimulationEngine {

private:
    GravitySystem gravity_system;
    std::vector<SpaceObject*>& space_objects;

    IPhysicsModel* physics_model;
    IIntegrator* integrator;

public:
    // Default constructor: uses GravitySystem + VelocityVerlet
    SimulationEngine(std::vector<SpaceObject*>& objects);

    // Custom constructor: inject physics model and integrator
    SimulationEngine(std::vector<SpaceObject*>& objects, IPhysicsModel* model, IIntegrator* integr);

    ~SimulationEngine();

    void run();

    void updateSimulation(double dt);
};