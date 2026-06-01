// Engine/World/UWorld.cpp
#include "UWorld.h"
#include "../Actors/UActor.h"
#include <memory>

void UWorld::AddActor(std::shared_ptr<UActor> actor)
{
    Actors.push_back(actor);
}

void UWorld::Tick(float deltaTime)
{
    for (auto& actor : Actors)
    {
        actor->Tick(deltaTime);
    }
}
