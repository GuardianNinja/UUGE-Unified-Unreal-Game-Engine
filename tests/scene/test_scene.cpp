#include "../../Engine/Scene/SceneGraph.h"

void run_scene_tests() {
    SceneGraph scene;

    Node* parent = scene.CreateNode();
    Node* child = scene.CreateNode();

    parent->LocalPosition = {10, 0, 0};
    child->LocalPosition = {5, 0, 0};

    scene.SetParent(child, parent);
    scene.UpdateWorldTransforms();

    report("Scene Graph World Transform",
        child->WorldPosition.X == 15);
}
