// Engine/World/UWorld.cpp
#include "UWorld.h"
#include "Engine/Actor/UActor.h"

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
