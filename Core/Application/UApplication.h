// Core/Application/UApplication.h
#pragma once

#include "Engine/Assets/AssetPipeline.h"
#include "Engine/ECS/ECSRegistry.h"
#include "Engine/Editor/EditorTools.h"
#include "Engine/Input/InputSystem.h"
#include "Engine/Memory/MemoryStrategy.h"
#include "Engine/Networking/NetworkingLayer.h"
#include "Engine/Physics/PhysicsEngine.h"
#include "Engine/Rendering/RenderPipeline.h"
#include "Engine/Rendering/ShaderSystem.h"
#include "Engine/Scene/SceneGraph.h"
#include "Engine/Serialization/Serializer.h"

class UApplication
{
public:
    UApplication();
    virtual ~UApplication();

    int Run();

protected:
    virtual bool Init();
    virtual void Shutdown();
    virtual void Tick(float deltaTime);

    ECSRegistry& GetECS();
    EditorTools& GetEditor();

private:
    bool bIsRunning;

protected:
    RenderPipeline RenderSystem{};
    ShaderSystem Shaders{};
    ECSRegistry ECS{};
    PhysicsEngine Physics{};
    AssetPipeline Assets{};
    EditorTools Editor{};
    Serializer SceneSerializer{};
    NetworkingLayer Network{};
    SceneGraph Scene{};
    InputSystem Input{};
    LinearArena Arena{1024 * 64};
};
