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
    // TODO: Init window, renderer, world, etc.
    return true;
}

void UApplication::Shutdown()
{
    // TODO: Cleanup
}

void UApplication::Tick(float deltaTime)
{
    // TODO: Update world, render frame
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

        // TODO: Poll OS events, input, etc.
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
