#pragma once

#include "Engine/Rendering/RenderTypes.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

using SceneNodeID = std::uint32_t;

struct SceneNode
{
    SceneNodeID Id = 0;
    SceneNodeID Parent = 0;
    std::vector<SceneNodeID> Children{};
    Vec3 LocalPosition{};
    Vec3 WorldPosition{};
};

class SceneGraph
{
public:
    SceneNodeID CreateNode(SceneNodeID parent = 0);
    bool SetLocalPosition(SceneNodeID id, const Vec3& localPosition);
    const SceneNode* GetNode(SceneNodeID id) const;

    void UpdateWorldTransforms();

private:
    void UpdateNodeRecursive(SceneNodeID id, const Vec3& parentWorld);

private:
    SceneNodeID NextNodeId = 1;
    std::unordered_map<SceneNodeID, SceneNode> Nodes{};
};
