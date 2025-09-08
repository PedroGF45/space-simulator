#pragma once

#include <vector>
#include "SpaceObject.h"
#include "../physics/GravitySystem.h"

class SimulationEngine {

	private:
		GravitySystem gravity_system;
		std::vector<SpaceObject*>& space_objects;

	public:
		SimulationEngine(std::vector<SpaceObject*>& objects);

		void run();

		void updateSimulation(double dt);
};