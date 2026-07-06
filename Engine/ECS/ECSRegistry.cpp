#include "ECSRegistry.h"

#include <algorithm>

EntityID ECSRegistry::CreateEntity()
{
    const EntityID entity = NextEntity++;
    LiveEntities.push_back(entity);
    return entity;
}

bool ECSRegistry::DestroyEntity(EntityID entity)
{
    auto it = std::find(LiveEntities.begin(), LiveEntities.end(), entity);
    if (it == LiveEntities.end())
    {
        return false;
    }

    LiveEntities.erase(it);
    Transforms.erase(entity);
    Velocities.erase(entity);
    return true;
}

void ECSRegistry::SetTransform(EntityID entity, const Transform& transform)
{
    Transforms[entity] = transform;
}

void ECSRegistry::SetVelocity(EntityID entity, const Velocity& velocity)
{
    Velocities[entity] = velocity;
}

Transform* ECSRegistry::GetTransform(EntityID entity)
{
    auto it = Transforms.find(entity);
    if (it == Transforms.end())
    {
        return nullptr;
    }
    return &it->second;
}

const Transform* ECSRegistry::GetTransform(EntityID entity) const
{
    auto it = Transforms.find(entity);
    if (it == Transforms.end())
    {
        return nullptr;
    }
    return &it->second;
}

Velocity* ECSRegistry::GetVelocity(EntityID entity)
{
    auto it = Velocities.find(entity);
    if (it == Velocities.end())
    {
        return nullptr;
    }
    return &it->second;
}

const Velocity* ECSRegistry::GetVelocity(EntityID entity) const
{
    auto it = Velocities.find(entity);
    if (it == Velocities.end())
    {
        return nullptr;
    }
    return &it->second;
}

void ECSRegistry::UpdateMovement(float deltaTime)
{
    for (EntityID entity : LiveEntities)
    {
        Transform* transform = GetTransform(entity);
        const Velocity* velocity = GetVelocity(entity);
        if (transform == nullptr || velocity == nullptr)
        {
            continue;
        }

        transform->Position.X += velocity->Value.X * deltaTime;
        transform->Position.Y += velocity->Value.Y * deltaTime;
        transform->Position.Z += velocity->Value.Z * deltaTime;
    }
}

std::vector<EntityID> ECSRegistry::GetEntities() const
{
    return LiveEntities;
}
