#pragma once

#include "Engine/ECS/ECSRegistry.h"

class EditorTools
{
public:
    void SetHierarchyVisible(bool visible);
    void SetInspectorVisible(bool visible);

    void SelectEntity(EntityID entity);
    EntityID GetSelectedEntity() const;

    void Update();

private:
    bool bHierarchyVisible = true;
    bool bInspectorVisible = true;
    EntityID SelectedEntity = 0;
};
