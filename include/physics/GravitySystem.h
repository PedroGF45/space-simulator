#pragma once
#include <vector>
#include <cmath>
#include "IPhysicsModel.h"
#include <simulation/SpaceObject.h>

class GravitySystem : public IPhysicsModel {

	private:
		const double GRAVITATIONAL_CONSTANT = 6.67430 * pow(10, -11);
		
	public:
		// IPhysicsModel implementation
		void computeForces(std::vector<SpaceObject*>& objects) override;

		// Backwards-compatible name
		void CalculateGravity(std::vector<SpaceObject*>& objects) { computeForces(objects); }
};