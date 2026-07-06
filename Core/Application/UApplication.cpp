// Core/Application/UApplication.cpp
#include "UApplication.h"

#include <chrono>
#include <thread>

UApplication::UApplication()
    : bIsRunning(false)
{
}

UApplication::~UApplication() {}

bool UApplication::Init()
{
    Shaders.RegisterShader("DefaultLit", "void main() { /* mock */ }");
    Shaders.CompileShader("DefaultLit");

    Assets.ImportAsset("/Game/Meshes/Cube.mesh", "mesh");

    Physics.AddRigidBody(RigidBody{});

    const SceneNodeID root = Scene.CreateNode();
    const SceneNodeID child = Scene.CreateNode(root);
    Scene.SetLocalPosition(child, Vec3{0.0f, 1.0f, 0.0f});

    Network.Connect("local://loopback");

    return true;
}

void UApplication::Shutdown()
{
    Arena.Reset();
}

void UApplication::Tick(float deltaTime)
{
    Input.Update();
    ECS.UpdateMovement(deltaTime);
    Physics.StepSimulation(deltaTime);
    Scene.UpdateWorldTransforms();

    RenderSystem.BeginFrame();

    for (EntityID entity : ECS.GetEntities())
    {
        const Transform* transform = ECS.GetTransform(entity);
        if (transform == nullptr)
        {
            continue;
        }

        Renderable renderable;
        renderable.LocalTransform = *transform;
        renderable.MeshData = Mesh{"ECSMesh", 36};
        renderable.MaterialData = Material{"DefaultMat", "DefaultLit"};
        renderable.Visible = true;
        RenderSystem.Submit(renderable);
    }

    RenderSystem.ExecuteFrame();
    RenderSystem.EndFrame();

    SceneSnapshot snapshot;
    snapshot.Name = "RuntimeScene";
    snapshot.EntityCount = ECS.GetEntities().size();
    snapshot.CameraPosition = Vec3{0.0f, 2.0f, -5.0f};

    Network.Send(Network.ReplicateState(snapshot));

    NetworkMessage message;
    while (Network.Poll(message))
    {
        // Drain local queue as a stand-in for a real transport poll step.
    }

    Editor.Update();
}

ECSRegistry& UApplication::GetECS()
{
    return ECS;
}

EditorTools& UApplication::GetEditor()
{
    return Editor;
}

int UApplication::Run()
{
    using clock = std::chrono::high_resolution_clock;

    if (!Init())
        return -1;

    bIsRunning = true;

    constexpr float kTargetFps = 60.0f;
    const auto targetFrameDuration = std::chrono::duration<float>(1.0f / kTargetFps);
    const auto maxRunDuration = std::chrono::duration<float>(5.0f);

    const auto startTime = clock::now();
    auto lastTime = startTime;

    while (bIsRunning)
    {
        const auto frameStart = clock::now();
        if (frameStart - startTime >= maxRunDuration)
        {
            bIsRunning = false;
            break;
        }

        const std::chrono::duration<float> elapsed = frameStart - lastTime;
        lastTime = frameStart;

        const float deltaTime = elapsed.count();

        Tick(deltaTime);

        const auto frameEnd = clock::now();
        const auto frameDuration = frameEnd - frameStart;
        if (frameDuration < targetFrameDuration)
        {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }
    }

    Shutdown();
    return 0;
}
