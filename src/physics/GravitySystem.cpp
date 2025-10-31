#include <vector>
#include <cmath>

#include <simulation/SpaceObject.h>
#include <simulation/Vector3D.h>
#include <physics/GravitySystem.h>

void GravitySystem::computeForces(std::vector<SpaceObject*>& objects) {
    for (int first_object_index = 0; first_object_index < objects.size(); first_object_index++) {
        Vector3D net_force(0, 0, 0);

        for (int second_object_index = 0; second_object_index < objects.size(); second_object_index++) {
            if (objects[first_object_index] == objects[second_object_index]) {
                continue;
            }
            else {

                // get positions
                Vector3D first_object_position = objects[first_object_index]->getPosition();
                Vector3D second_object_position = objects[second_object_index]->getPosition();

                // calculate the direction vector
                Vector3D direction_vector = second_object_position - first_object_position;

                // calculate the distance between the objects
                double distance = direction_vector.getMagnitude();

                // this cannot happen since the center of mass cannot be at the same position
                if (distance == 0) {
                    continue;
                }

                // calculate the magnitude of the force
                double force_magnitude = GRAVITATIONAL_CONSTANT * ((objects[first_object_index]->getMass() * objects[second_object_index]->getMass()) / (distance * distance));

                // calculate the force vector
                Vector3D unit_vector = direction_vector / distance;
                Vector3D force_vector = unit_vector * force_magnitude;

                // update the net_force
                net_force += force_vector;
            }
        }

        // update object net force
        objects[first_object_index]->setNetForce(net_force);

        // Also update the acceleration for convenience
        objects[first_object_index]->updateAcceleration();
    }
}