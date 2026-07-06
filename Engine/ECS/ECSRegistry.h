#pragma once

#include "Engine/Rendering/RenderTypes.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

using EntityID = std::uint32_t;

struct Velocity
{
    Vec3 Value{};
};

class ECSRegistry
{
public:
    EntityID CreateEntity();
    bool DestroyEntity(EntityID entity);

    void SetTransform(EntityID entity, const Transform& transform);
    void SetVelocity(EntityID entity, const Velocity& velocity);

    Transform* GetTransform(EntityID entity);
    const Transform* GetTransform(EntityID entity) const;

    Velocity* GetVelocity(EntityID entity);
    const Velocity* GetVelocity(EntityID entity) const;

    void UpdateMovement(float deltaTime);
    std::vector<EntityID> GetEntities() const;

private:
    EntityID NextEntity = 1;
    std::vector<EntityID> LiveEntities{};
    std::unordered_map<EntityID, Transform> Transforms{};
    std::unordered_map<EntityID, Velocity> Velocities{};
};
