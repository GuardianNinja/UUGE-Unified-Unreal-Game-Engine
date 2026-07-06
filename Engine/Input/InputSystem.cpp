#include "InputSystem.h"

void InputSystem::PressKey(const std::string& key)
{
    KeyStates[key] = true;
}

void InputSystem::ReleaseKey(const std::string& key)
{
    KeyStates[key] = false;
}

bool InputSystem::IsKeyDown(const std::string& key) const
{
    auto it = KeyStates.find(key);
    if (it == KeyStates.end())
    {
        return false;
    }
    return it->second;
}

float InputSystem::GetAxis(const std::string& axisName) const
{
    if (axisName != "Horizontal")
    {
        return 0.0f;
    }

    float value = 0.0f;
    if (IsKeyDown("A") || IsKeyDown("Left"))
    {
        value -= 1.0f;
    }
    if (IsKeyDown("D") || IsKeyDown("Right"))
    {
        value += 1.0f;
    }
    return value;
}

void InputSystem::Update()
{
    // Reserved for future event queue integration.
}
