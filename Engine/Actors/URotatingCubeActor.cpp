// Game/Actors/URotatingCubeActor.cpp
#include "URotatingCubeActor.h"

void URotatingCubeActor::Tick(float deltaTime)
{
    UActor::Tick(deltaTime);

    Yaw += 90.0f * deltaTime; // degrees per second
    if (Yaw > 360.0f)
    {
        Yaw -= 360.0f;
    }
}
