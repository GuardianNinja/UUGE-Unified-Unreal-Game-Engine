#include "../../Engine/Physics/Physics.h"

void run_physics_tests() {
    Physics physics;

    RigidBody body;
    body.Velocity.Y = 0.0f;

    physics.AddBody(&body);
    physics.StepSimulation(1.0f);

    report("Physics Gravity", body.Velocity.Y < 0.0f);
}
