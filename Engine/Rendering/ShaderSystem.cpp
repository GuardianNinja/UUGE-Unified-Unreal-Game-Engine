#include "ShaderSystem.h"

void ShaderSystem::RegisterShader(const std::string& name, const std::string& source)
{
    ShaderRecord record;
    record.Name = name;
    record.Source = source;
    record.IsCompiled = false;
    Shaders[name] = record;
}

bool ShaderSystem::CompileShader(const std::string& name)
{
    auto it = Shaders.find(name);
    if (it == Shaders.end())
    {
        return false;
    }

    // Mock compile: a non-empty source string is considered compile success.
    it->second.IsCompiled = !it->second.Source.empty();
    return it->second.IsCompiled;
}

bool ShaderSystem::IsCompiled(const std::string& name) const
{
    auto it = Shaders.find(name);
    if (it == Shaders.end())
    {
        return false;
    }

    return it->second.IsCompiled;
}
