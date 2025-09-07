#pragma once
#include <string>
#include "Vector3D.h"

class SpaceObject {

private:
	std::string name;
	double mass;
	Vector3D position;
	Vector3D velocity;
	Vector3D acceleration;
	Vector3D net_force;

public:
	SpaceObject(std::string name, double mass, Vector3D position, Vector3D velocity, Vector3D acceleration);

	// Getters
	std::string getName() const;
	double getMass() const;
	Vector3D getPosition() const;
	Vector3D getVelocity() const;
	Vector3D getAcceleration() const;
	Vector3D getNetForce() const;

	// Setters
	void setPosition(Vector3D new_position);
	void setVelocity(Vector3D new_velocity);
	void setAcceleration(Vector3D new_acceleration);
	void setNetForce(Vector3D new_net_force);

	// Physics methods
	void updateObject(double dt);
	void updateAcceleration();
};