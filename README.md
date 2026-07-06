🟦 UUGE — Unified Unreal‑Style Game Engine
A modular, multi‑subsystem C++ game engine inspired by Unreal Engine’s architecture.

UUGE is a modern, component‑driven, editor‑ready game engine built from the ground up with a clean subsystem architecture.
It includes a rendering pipeline, ECS, physics, asset management, editor tools, networking, serialization, scene graph, input system, and custom memory management.

🟪 Engine Architecture Overview
UUGE is composed of the following major subsystems:

Rendering Pipeline — Frame stages, culling, draw batching

Shader System — Registration, compilation, shader records

ECS (Entity Component System) — Entities, transforms, velocities, movement systems

Physics Engine — Rigid bodies, gravity, collision floor

Asset Pipeline — Import, metadata, caching

Editor Tools — Hierarchy, inspector, entity selection

Scene Graph — Parent/child nodes, world transforms

Serialization System — Scene snapshot serialization/deserialization

Networking Layer — Local transport, replication, message queue

Input System — Key states, axis mapping

Memory Strategy — Linear arena allocator, object pool

All subsystems are initialized and orchestrated through UApplication.

🟦 Rendering Pipeline
The rendering pipeline is structured into three Unreal‑style stages:

Prepare Stage
Builds GPU command data and sorts batches.

Culling Stage
cpp
if (renderable.Visible) {
    CulledRenderables.push_back(&renderable);
}
Draw Stage
Counts draw calls and executes the frame.

Supports:

Per‑frame renderable submission

Camera data

Material + mesh binding

Visibility culling

Draw call statistics

🟦 Shader System
cpp
Shaders.RegisterShader("DefaultLit", "void main() { /* mock */ }");
Shaders.CompileShader("DefaultLit");
🟦 Entity Component System (ECS)
cpp
transform->Position.X += velocity->Value.X * deltaTime;
Includes:

Entity creation/destruction

Transform components

Velocity components

Movement system

🟦 Physics Engine
cpp
body.Velocity.Y += Gravity * deltaTime;
Includes:

Rigid body registry

Gravity simulation

Floor collision

Velocity integration

🟦 Asset Pipeline
cpp
Assets.ImportAsset("/Game/Meshes/Cube.mesh", "mesh");
🟦 Editor Tools
cpp
Editor.SelectEntity(DemoEntity);
🟦 Scene Graph
cpp
node.WorldPosition.X = parentWorld.X + node.LocalPosition.X;
🟦 Serialization System
Example output:

Code
name=RuntimeScene; entities=1; cam=0,2,-5
🟦 Networking Layer
cpp
Network.Send(Network.ReplicateState(snapshot));
🟦 Input System
Supports:

Key press/release

Axis mapping

Horizontal movement (A/D, Left/Right)

🟦 Memory Management Strategy
cpp
void* ptr = arena.Allocate(size, alignment);
arena.Reset();
🟦 Application Lifecycle
cpp
Input.Update();
ECS.UpdateMovement(deltaTime);
Physics.StepSimulation(deltaTime);
Scene.UpdateWorldTransforms();
RenderSystem.BeginFrame();
RenderSystem.ExecuteFrame();
RenderSystem.EndFrame();
Editor.Update();
🟦 Build Instructions
Code
cmake -S . -B build
cmake --build build
./build/uuge_engine
🟦 Demo
The demo:

Creates a world

Spawns a rotating cube actor

Creates an ECS entity

Applies velocity

Selects entity in editor

Runs at ~60 FPS

🟦 Roadmap
GPU backend (Vulkan/Metal/DirectX)

Material graph

Blueprint‑style scripting

Full editor UI

Asset cooking pipeline

Physics broadphase

Networking replication channels

Animation system

Audio engine

Terrain system

Lighting system
