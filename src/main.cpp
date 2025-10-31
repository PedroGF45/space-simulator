#include <iostream>
#include <vector>
#include <simulation/SpaceObject.h>
#include <simulation/Vector3D.h>
#include <physics/GravitySystem.h>
#include <simulation/SimulationEngine.h>

int main(int argc, char* argv[]) {
    (void)argc; (void)argv; // Mark unused parameters to silence MSVC C4100 warnings

    // Sun
    Vector3D sun_position(0, 0, 0);
    Vector3D sun_velocity(0, 0, 0);
    Vector3D sun_acceleration(0, 0, 0);
    double sun_mass = 1.989e30;

    SpaceObject sun("Sun", sun_mass, sun_position, sun_velocity, sun_acceleration);

    const double GRAVITATIONAL_CONSTANT = 6.67430 * pow(10, -11);

    Vector3D mercury_position(5.79e10, 0, 0);
    double mercury_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / mercury_position.getMagnitude());
    SpaceObject mercury("Mercury", 3.301e23, mercury_position, { 0, mercury_orbital_velocity, 0 }, { 0, 0, 0 });

    Vector3D venus_position(1.082e11, 0, 0);
    double venus_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / venus_position.getMagnitude());
    SpaceObject venus("Venus", 4.867e24, venus_position, { 0, venus_orbital_velocity, 0 }, { 0, 0, 0 });

    Vector3D earth_position(1.496e11, 0, 0);
    double earth_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / earth_position.getMagnitude());
    SpaceObject earth("Earth", 5.972e24, earth_position, { 0, earth_orbital_velocity, 0 }, { 0, 0, 0 });

    Vector3D mars_position(2.279e11, 0, 0);
    double mars_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / mars_position.getMagnitude());
    SpaceObject mars("Mars", 6.417e23, mars_position, { 0, mars_orbital_velocity, 0 }, { 0, 0, 0 });

    Vector3D jupiter_position(7.785e11, 0, 0);
    double jupiter_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / jupiter_position.getMagnitude());
    SpaceObject jupiter("Jupiter", 1.898e27, jupiter_position, { 0, jupiter_orbital_velocity, 0 }, { 0, 0, 0 });

    Vector3D saturn_position(1.433e12, 0, 0);
    double saturn_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / saturn_position.getMagnitude());
    SpaceObject saturn("Saturn", 5.683e26, saturn_position, { 0, saturn_orbital_velocity, 0 }, { 0, 0, 0 });

    Vector3D uranus_position(2.872e12, 0, 0);
    double uranus_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / uranus_position.getMagnitude());
    SpaceObject uranus("Uranus", 8.681e25, uranus_position, { 0, uranus_orbital_velocity, 0 }, { 0, 0, 0 });

    Vector3D neptune_position(4.495e12, 0, 0);
    double neptune_orbital_velocity = std::sqrt(GRAVITATIONAL_CONSTANT * sun_mass / neptune_position.getMagnitude());
    SpaceObject neptune("Neptune", 1.024e26, neptune_position, { 0, neptune_orbital_velocity, 0 }, { 0, 0, 0 });

    // Add objects to system
    std::vector<SpaceObject*> objects = {
        &sun, &mercury, &venus, &earth, &mars,
        &jupiter, &saturn, &uranus, &neptune
    };

    SimulationEngine simulation_engine(objects);

    // Run the simulation for a number of steps to show the orbits
    const double TIME_STEP = 3600.0; // 1 hour in seconds
    const int SIMULATION_STEPS = 1000;

    for (int i = 0; i < SIMULATION_STEPS; ++i) {
        simulation_engine.updateSimulation(TIME_STEP);

        // Print the position of each planet to see the simulation
        if (i % 50 == 0) { // Print every 50 steps for clarity
            std::cout << "--- Step " << i << " ---" << std::endl;
            for (auto object : objects) {
                std::cout << object->getName() << ": " << object->getPosition().getX()
                    << ", " << object->getPosition().getY()
                    << ", " << object->getPosition().getZ() << std::endl;
            }
        }
    }

    return 0;
}
