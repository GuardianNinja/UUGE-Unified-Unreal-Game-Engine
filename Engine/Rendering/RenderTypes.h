#pragma once

#include <string>
#include <vector>

struct Vec3
{
    float X = 0.0f;
    float Y = 0.0f;
    float Z = 0.0f;
};

struct Transform
{
    Vec3 Position{};
    Vec3 Rotation{};
    Vec3 Scale{1.0f, 1.0f, 1.0f};
};

struct Mesh
{
    std::string Name;
    std::size_t VertexCount = 0;
};

struct Material
{
    std::string Name;
    std::string ShaderName;
};

struct Renderable
{
    Transform LocalTransform{};
    Mesh MeshData{};
    Material MaterialData{};
    bool Visible = true;
};

struct Camera
{
    Transform ViewTransform{};
};

struct RenderFrame
{
    std::vector<Renderable> Renderables;
    Camera ActiveCamera{};
};
