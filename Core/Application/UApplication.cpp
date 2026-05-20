// Core/Application/UApplication.cpp
#include "UApplication.h"
#include <chrono>

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
    if (!Init())
        return -1;

    bIsRunning = true;

    auto lastTime = std::chrono::high_resolution_clock::now();

    while (bIsRunning)
    {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = now - lastTime;
        lastTime = now;

        float deltaTime = elapsed.count();

        // TODO: Poll OS events, input, etc.

        Tick(deltaTime);
    }

    Shutdown();
    return 0;
}
