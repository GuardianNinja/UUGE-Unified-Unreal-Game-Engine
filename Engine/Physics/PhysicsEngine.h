#pragma once

#include "Engine/Rendering/RenderTypes.h"

#include <cstdint>
#include <vector>

using RigidBodyID = std::uint32_t;

struct RigidBody
{
    RigidBodyID Id = 0;
    Vec3 Position{};
    Vec3 Velocity{};
    bool IsStatic = false;
};

class PhysicsEngine
{
public:
    RigidBodyID AddRigidBody(const RigidBody& body);
    bool RemoveRigidBody(RigidBodyID id);

    void StepSimulation(float deltaTime);
    std::vector<RigidBody>& GetBodies();
    const std::vector<RigidBody>& GetBodies() const;

private:
    RigidBodyID NextBodyId = 1;
    std::vector<RigidBody> Bodies{};
    float Gravity = -9.81f;
};
