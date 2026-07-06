#include "EditorTools.h"

#include <iostream>

void EditorTools::SetHierarchyVisible(bool visible)
{
    bHierarchyVisible = visible;
}

void EditorTools::SetInspectorVisible(bool visible)
{
    bInspectorVisible = visible;
}

void EditorTools::SelectEntity(EntityID entity)
{
    SelectedEntity = entity;
}

EntityID EditorTools::GetSelectedEntity() const
{
    return SelectedEntity;
}

void EditorTools::Update()
{
    if (!bHierarchyVisible && !bInspectorVisible)
    {
        return;
    }

    if (SelectedEntity != 0)
    {
        std::cout << "[Editor] Selected Entity: " << SelectedEntity << "\n";
    }
}
