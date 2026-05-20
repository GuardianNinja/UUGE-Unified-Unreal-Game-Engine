// Engine/Actor/UActor.h
#pragma once
#include <vector>
#include <memory>

class UComponent;

class UActor
{
public:
    virtual ~UActor() = default;

    virtual void Tick(float deltaTime);

    template<typename T, typename... Args>
    T* AddComponent(Args&&... args)
    {
        auto comp = std::make_shared<T>(std::forward<Args>(args)...);
        comp->SetOwner(this);
        Components.push_back(comp);
        return comp.get();
    }

protected:
    std::vector<std::shared_ptr<UComponent>> Components;
};
