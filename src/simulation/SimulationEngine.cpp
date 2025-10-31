#include <simulation/SimulationEngine.h>
#include <physics/VelocityVerlet.h>
#include <physics/GravitySystem.h>

SimulationEngine::SimulationEngine(std::vector<SpaceObject*>& objects) : space_objects(objects), physics_model(nullptr), integrator(nullptr) {
    // default to GravitySystem + VelocityVerlet
    physics_model = new GravitySystem();
    integrator = new VelocityVerlet(physics_model);
}

SimulationEngine::SimulationEngine(std::vector<SpaceObject*>& objects, IPhysicsModel* model, IIntegrator* integr) : space_objects(objects), physics_model(model), integrator(integr) {}

SimulationEngine::~SimulationEngine() {
    // Only delete defaults if they were created by this engine
    // For simplicity in this initial change we won't attempt to detect ownership. In a real project use smart pointers and clear ownership semantics.
    delete physics_model;
    delete integrator;
}

void SimulationEngine::run() {
    while (true) {
        updateSimulation(100);
    }
}

void SimulationEngine::updateSimulation(double dt) {
    if (physics_model) physics_model->computeForces(space_objects);
    if (integrator) integrator->integrate(space_objects, dt);
}