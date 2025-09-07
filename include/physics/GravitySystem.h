#pragma once
#include <vector>
#include <cmath>
#include "../simulation/SpaceObject.h"

class GravitySystem {

	private:
		const double GRAVITATIONAL_CONSTANT = 6.67430 * pow(10, -11);
		
	public:
		void CalculateGravity(std::vector<SpaceObject*>& objects);
};