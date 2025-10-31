#include <physics/VelocityVerlet.h>
#include <physics/IPhysicsModel.h>
#include <simulation/SpaceObject.h>

void VelocityVerlet::integrate(std::vector<SpaceObject*>& objects, double dt) {
    if (!physics_model) return;

    if (objects.empty()) return;

    // 1) Store current accelerations a(t) for each object and update positions:
    // x(t+dt) = x(t) + v(t)*dt + 0.5*a(t)*dt^2
    std::vector<Vector3D> old_accels;
    old_accels.reserve(objects.size());

    for (auto obj : objects) {
        auto a = obj->getAcceleration();
        old_accels.push_back(a);
        auto v = obj->getVelocity();
        auto x = obj->getPosition();

        obj->setPosition(x + (v * dt) + (a * (0.5 * dt * dt)));
    }

    // 2) Recompute forces/accelerations at new positions
    physics_model->computeForces(objects);

    // 3) Update velocities: v(t+dt) = v(t) + 0.5*(a(t) + a(t+dt))*dt
    for (size_t i = 0; i < objects.size(); ++i) {
        auto obj = objects[i];
        // updateAcceleration computes a(t+dt) from net_force/mass
        obj->updateAcceleration();
        auto a_new = obj->getAcceleration();
        auto v = obj->getVelocity();

        obj->setVelocity(v + ((old_accels[i] + a_new) * (0.5 * dt)));
    }
}
