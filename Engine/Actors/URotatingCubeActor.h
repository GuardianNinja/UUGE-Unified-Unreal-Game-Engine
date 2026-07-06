// Game/Actors/URotatingCubeActor.h
#pragma once
#include "Engine/Actors/UActor.h"

class URotatingCubeActor : public UActor
{
public:
    virtual void Tick(float deltaTime) override;

private:
    float Yaw = 0.0f;
};
