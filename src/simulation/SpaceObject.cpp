#include <simulation/SpaceObject.h>

// Constructor
SpaceObject::SpaceObject(std::string name, double mass, Vector3D position, Vector3D velocity, Vector3D acceleration) :
    name(name), mass(mass), position(position), velocity(velocity), acceleration(acceleration), net_force(0, 0, 0) {
};

// Getters
std::string SpaceObject::getName() const { return name; };
double SpaceObject::getMass() const { return mass; };
Vector3D SpaceObject::getPosition() const { return position; };
Vector3D SpaceObject::getVelocity() const { return velocity; };
Vector3D SpaceObject::getAcceleration() const { return acceleration; };
Vector3D SpaceObject::getNetForce() const { return net_force; };

// Setters
void SpaceObject::setPosition(Vector3D new_position) { position = new_position; };
void SpaceObject::setVelocity(Vector3D new_velocity) { velocity = new_velocity; };
void SpaceObject::setAcceleration(Vector3D new_acceleration) { acceleration = new_acceleration; };
void SpaceObject::setNetForce(Vector3D new_net_force) { net_force = new_net_force; };

// Physics methods
void SpaceObject::updateAcceleration() {
    acceleration = net_force / mass;
}

void SpaceObject::updateObject(double dt) {
    // Update velocity based on acceleration and time step (dt)
    velocity = velocity + (acceleration * dt);

    // Update position based on velocity and time step (dt)
    position = position + (velocity * dt);
}
