🟦 UUGE — Unified Unreal‑Style Game Engine
A modular, multi‑subsystem C++ game engine inspired by Unreal Engine’s architecture.

UUGE is a modern, component‑driven, editor‑ready game engine built from the ground up with a clean subsystem architecture.
It includes a rendering pipeline, ECS, physics, asset management, editor tools, networking, serialization, scene graph, input system, and custom memory management.

This README documents the engine’s architecture in the same style used by Unreal Engine’s technical documentation.

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

1. Prepare Stage
Builds GPU command data, sorts batches (placeholder for future GPU backend).

2. Culling Stage
Filters visible renderables:

cpp
if (renderable.Visible) { CulledRenderables.push_back(&renderable); }

3. Draw Stage
Counts draw calls and executes the frame.

The pipeline supports:

Per‑frame renderable submission

Camera data

Material + mesh binding

Visibility culling

Draw call statistics

🟦 Shader System

The shader system allows:

Shader registration

Mock compilation

Shader record tracking

Example:

cpp
Shaders.RegisterShader("DefaultLit", "void main() { /* mock */ }");
Shaders.CompileShader("DefaultLit");

🟦 Entity Component System (ECS)

Your ECS includes:

Entity creation/destruction

Transform components

Velocity components

Movement system

Movement update:

cpp
transform->Position.X += velocity->Value.X * deltaTime;

This mirrors Unreal’s Actor + Component model but in a pure ECS form.

🟦 Physics Engine

Your physics engine includes:

Rigid body registry

Gravity simulation

Floor collision

Velocity integration

Example gravity step:

cpp
body.Velocity.Y += Gravity * deltaTime;

🟦 Asset Pipeline

Supports:

Asset import

Metadata caching

Type tagging

Asset lookup

Example:

cpp
Assets.ImportAsset("/Game/Meshes/Cube.mesh", "mesh");

🟦 Editor Tools

Your editor subsystem includes:

Hierarchy visibility

Inspector visibility

Entity selection

Editor update loop

Example:

cpp
Editor.SelectEntity(DemoEntity);

This is the foundation for a full Unreal‑style editor.

🟦 Scene Graph

Supports:

Parent/child relationships

Local transforms

World transform propagation

World transform update:

cpp
node.WorldPosition.X = parentWorld.X + node.LocalPosition.X;

🟦 Serialization System

Serializes scene snapshots:

Name

Entity count

Camera position

Example output:

Code
name=RuntimeScene; entities=1; cam=0,2,-5
🟦 Networking Layer

Provides:

Local endpoint connection

Message queue

Snapshot replication

Example:

cpp
Network.Send(Network.ReplicateState(snapshot));

🟦 Input System

Supports:

Key press/release

Axis mapping

Horizontal movement (A/D, Left/Right)

🟦 Memory Management Strategy

Your memory system includes:

Linear Arena Allocator

Object Pool

Memory statistics

Arena allocation:

cpp
void* ptr = arena.Allocate(size, alignment);
Reset per frame:

cpp
Arena.Reset();

🟦 Application Lifecycle
UApplication orchestrates all subsystems:

Init

Tick

Shutdown

ECS updates

Physics simulation

Rendering

Networking

Editor updates

Tick loop example:

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

🟦 Roadmap (Unreal‑Style)
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
