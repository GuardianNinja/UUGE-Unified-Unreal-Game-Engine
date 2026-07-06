#include "PhysicsEngine.h"

#include <algorithm>

RigidBodyID PhysicsEngine::AddRigidBody(const RigidBody& body)
{
    RigidBody newBody = body;
    newBody.Id = NextBodyId++;
    Bodies.push_back(newBody);
    return newBody.Id;
}

bool PhysicsEngine::RemoveRigidBody(RigidBodyID id)
{
    auto it = std::find_if(Bodies.begin(), Bodies.end(), [id](const RigidBody& body) {
        return body.Id == id;
    });

    if (it == Bodies.end())
    {
        return false;
    }

    Bodies.erase(it);
    return true;
}

void PhysicsEngine::StepSimulation(float deltaTime)
{
    for (RigidBody& body : Bodies)
    {
        if (body.IsStatic)
        {
            continue;
        }

        body.Velocity.Y += Gravity * deltaTime;

        body.Position.X += body.Velocity.X * deltaTime;
        body.Position.Y += body.Velocity.Y * deltaTime;
        body.Position.Z += body.Velocity.Z * deltaTime;

        if (body.Position.Y < 0.0f)
        {
            body.Position.Y = 0.0f;
            if (body.Velocity.Y < 0.0f)
            {
                body.Velocity.Y = 0.0f;
            }
        }
    }
}

std::vector<RigidBody>& PhysicsEngine::GetBodies()
{
    return Bodies;
}

const std::vector<RigidBody>& PhysicsEngine::GetBodies() const
{
    return Bodies;
}
