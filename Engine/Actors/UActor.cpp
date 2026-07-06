// Engine/Actors/UActor.cpp
#include "UActor.h"
#include "UComponent.h"

void UActor::Tick(float deltaTime)
{
    for (auto& comp : Components)
    {
        comp->Tick(deltaTime);
    }
}
