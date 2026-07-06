cmake_minimum_required(VERSION 3.16)

project(uuge_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(uuge_engine
    main.cpp
    Core/Application/UApplication.cpp
    Engine/World/UWorld.cpp
    Engine/Actors/UActor.cpp
    Engine/Actors/URotatingCubeActor.cpp
    Engine/Rendering/RenderPipeline.cpp
    Engine/Rendering/ShaderSystem.cpp
    Engine/ECS/ECSRegistry.cpp
    Engine/Physics/PhysicsEngine.cpp
    Engine/Assets/AssetPipeline.cpp
    Engine/Editor/EditorTools.cpp
    Engine/Serialization/Serializer.cpp
    Engine/Networking/NetworkingLayer.cpp
    Engine/Scene/SceneGraph.cpp
    Engine/Input/InputSystem.cpp
    Engine/Memory/MemoryStrategy.cpp
)

target_include_directories(uuge_engine PRIVATE )
