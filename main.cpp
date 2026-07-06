// main.cpp (Engine launcher)
#include "Core/Application/UApplication.h"
#include "Engine/Actors/URotatingCubeActor.h"
#include "Engine/World/UWorld.h"

#include <iostream>
#include <memory>

class UUGEGameApp : public UApplication
{
protected:
    bool Init() override
    {
        if (!UApplication::Init())
            return false;

        World = std::make_unique<UWorld>();
        World->AddActor(std::make_shared<URotatingCubeActor>());

        DemoEntity = GetECS().CreateEntity();

        Transform transform;
        transform.Position = Vec3{0.0f, 1.0f, 0.0f};
        GetECS().SetTransform(DemoEntity, transform);

        Velocity velocity;
        velocity.Value = Vec3{1.0f, 0.0f, 0.0f};
        GetECS().SetVelocity(DemoEntity, velocity);

        GetEditor().SelectEntity(DemoEntity);

        return true;
    }

    void Tick(float deltaTime) override
    {
        UApplication::Tick(deltaTime);

        if (World)
        {
            World->Tick(deltaTime);
        }

        ++FrameCount;
        AccumulatedTime += deltaTime;
        if (FrameCount % 30 == 0)
        {
            const float avgMs = (AccumulatedTime / static_cast<float>(FrameCount)) * 1000.0f;
            std::cout << "Frame " << FrameCount << " | dt=" << (deltaTime * 1000.0f)
                      << " ms | avg=" << avgMs << " ms\n";
        }
    }

private:
    std::unique_ptr<UWorld> World;
    EntityID DemoEntity = 0;
    std::size_t FrameCount = 0;
    float AccumulatedTime = 0.0f;
};

int main()
{
    UUGEGameApp app;
    return app.Run();
}
