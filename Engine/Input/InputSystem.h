#pragma once

#include <string>
#include <unordered_map>

class InputSystem
{
public:
    void PressKey(const std::string& key);
    void ReleaseKey(const std::string& key);
    bool IsKeyDown(const std::string& key) const;

    float GetAxis(const std::string& axisName) const;
    void Update();

private:
    std::unordered_map<std::string, bool> KeyStates{};
};
