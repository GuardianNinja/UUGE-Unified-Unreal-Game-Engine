#pragma once

#include <string>
#include <unordered_map>

struct ShaderRecord
{
    std::string Name;
    std::string Source;
    bool IsCompiled = false;
};

class ShaderSystem
{
public:
    void RegisterShader(const std::string& name, const std::string& source);
    bool CompileShader(const std::string& name);
    bool IsCompiled(const std::string& name) const;

private:
    std::unordered_map<std::string, ShaderRecord> Shaders{};
};
