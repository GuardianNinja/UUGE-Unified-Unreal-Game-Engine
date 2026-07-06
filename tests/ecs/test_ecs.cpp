#include "../../Engine/ECS/ECS.h"
#include "../../Engine/ECS/Components.h"

void run_ecs_tests() {
    ECS ecs;

    Entity e = ecs.CreateEntity();
    ecs.AddComponent<Transform>(e);
    ecs.AddComponent<Velocity>(e, {1.0f, 0.0f, 0.0f});

    ecs.UpdateMovement(1.0f);

    auto* t = ecs.GetComponent<Transform>(e);

    report("ECS Movement System", t->Position.X == 1.0f);
    report("ECS Component Retrieval", t != nullptr);
}
