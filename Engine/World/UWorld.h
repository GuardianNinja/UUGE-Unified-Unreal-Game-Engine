// Engine/World/UWorld.h
#pragma once

#include <vector>
#include <memory>

class UActor;

class UWorld
{
public:
    void AddActor(std::shared_ptr<UActor> actor);
    void Tick(float deltaTime);

private:
    std::vector<std::shared_ptr<UActor>> Actors;
};
