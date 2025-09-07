#include "../../include/simulation/SimulationEngine.h"

SimulationEngine::SimulationEngine(std::vector<SpaceObject*>& objects) : space_objects(objects) {}

void SimulationEngine::run() {
	while (true) {
		updateSimulation(100);
	}
}

void SimulationEngine::updateSimulation(double dt) {
	gravity_system.CalculateGravity(space_objects);

	for (auto object : space_objects) {
		object->updateAcceleration();
		object->updateObject(dt);
	}
}