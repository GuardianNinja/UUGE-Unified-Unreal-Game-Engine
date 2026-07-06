#pragma once

#include "Engine/Rendering/RenderTypes.h"

#include <string>

struct SceneSnapshot
{
    std::string Name;
    std::size_t EntityCount = 0;
    Vec3 CameraPosition{};
};

class Serializer
{
public:
    std::string SerializeSceneSnapshot(const SceneSnapshot& snapshot) const;
    bool DeserializeSceneSnapshot(const std::string& text, SceneSnapshot& outSnapshot) const;
};
