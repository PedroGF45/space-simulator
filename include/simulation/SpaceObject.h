#pragma once
#include <string>
#include "Vector3D.h"

class SpaceObject {

	private:
		std::string name;
		Vector3D position;
		Vector3D velocity;
		Vector3D acceleration;
		double mass;

	public:
		SpaceObject(std::string name, double mass, Vector3D position, Vector3D velocity, Vector3D acceleration) :
			name(name), mass(mass), position(position), velocity(velocity), acceleration(acceleration) {
		};

		std::string getName() const { return name; };
		Vector3D getPosition() const { return position; };
		Vector3D getVelocity() const { return velocity; };
		Vector3D getAcceleration() const { return acceleration; };
		double getMass() const { return mass; };

		void setPosition(Vector3D new_position) { position = new_position; };
		void setVelocity(Vector3D new_velocity) { velocity = new_velocity; };
		void setAcceleration(Vector3D new_acceleration) { acceleration = new_acceleration; };

		Vector3D CalculateGravity(SpaceObject spaceObject) {};
};