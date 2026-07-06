#include "SceneGraph.h"

SceneNodeID SceneGraph::CreateNode(SceneNodeID parent)
{
    SceneNode node;
    node.Id = NextNodeId++;
    node.Parent = parent;

    if (parent != 0)
    {
        auto parentIt = Nodes.find(parent);
        if (parentIt != Nodes.end())
        {
            parentIt->second.Children.push_back(node.Id);
        }
        else
        {
            node.Parent = 0;
        }
    }

    Nodes[node.Id] = node;
    return node.Id;
}

bool SceneGraph::SetLocalPosition(SceneNodeID id, const Vec3& localPosition)
{
    auto it = Nodes.find(id);
    if (it == Nodes.end())
    {
        return false;
    }

    it->second.LocalPosition = localPosition;
    return true;
}

const SceneNode* SceneGraph::GetNode(SceneNodeID id) const
{
    auto it = Nodes.find(id);
    if (it == Nodes.end())
    {
        return nullptr;
    }

    return &it->second;
}

void SceneGraph::UpdateWorldTransforms()
{
    for (const auto& pair : Nodes)
    {
        if (pair.second.Parent == 0)
        {
            UpdateNodeRecursive(pair.first, Vec3{});
        }
    }
}

void SceneGraph::UpdateNodeRecursive(SceneNodeID id, const Vec3& parentWorld)
{
    auto it = Nodes.find(id);
    if (it == Nodes.end())
    {
        return;
    }

    SceneNode& node = it->second;
    node.WorldPosition.X = parentWorld.X + node.LocalPosition.X;
    node.WorldPosition.Y = parentWorld.Y + node.LocalPosition.Y;
    node.WorldPosition.Z = parentWorld.Z + node.LocalPosition.Z;

    for (SceneNodeID child : node.Children)
    {
        UpdateNodeRecursive(child, node.WorldPosition);
    }
}
