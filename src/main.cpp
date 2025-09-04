#include <iostream>
#include "SpaceObject.h"
#include "Vector3D.h"

int main() {
    
    Vector3D earth_position (10, 20, 30);
    Vector3D earth_velocity (20, 30, 10);
    Vector3D earth_acceleration (30, 10, 20);

    SpaceObject earth = SpaceObject("Earth", earth_position, earth_velocity, earth_acceleration);

    std::cout << "Earth name is: " << earth.getName() << std::endl;
    std::cout << "Earth position is: (" << earth.getPosition().getX() << ", "
        << earth.getPosition().getY() << ", "
        << earth.getPosition().getZ() << ")" << std::endl;

    std::cout << "Earth velocity is: (" << earth.getVelocity().getX() << ", "
        << earth.getVelocity().getY() << ", "
        << earth.getVelocity().getZ() << ")" << std::endl;

    std::cout << "Earth acceleration is: (" << earth.getAcceleration().getX() << ", "
        << earth.getAcceleration().getY() << ", "
        << earth.getAcceleration().getZ() << ")" << std::endl;

}