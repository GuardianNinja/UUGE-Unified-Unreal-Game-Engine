// Engine/Actors/UComponent.h
#pragma once

class UActor;

class UComponent
{
public:
    virtual ~UComponent() = default;
    virtual void Tick(float deltaTime) {}

    void SetOwner(UActor* owner) { Owner = owner; }
    UActor* GetOwner() const { return Owner; }

private:
    UActor* Owner = nullptr;
};
