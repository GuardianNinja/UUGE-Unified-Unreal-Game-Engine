#include "Serializer.h"

#include <sstream>

std::string Serializer::SerializeSceneSnapshot(const SceneSnapshot& snapshot) const
{
    std::ostringstream stream;
    stream << "name=" << snapshot.Name << ";"
           << "entities=" << snapshot.EntityCount << ";"
           << "cam=" << snapshot.CameraPosition.X << "," << snapshot.CameraPosition.Y << ","
           << snapshot.CameraPosition.Z;
    return stream.str();
}

bool Serializer::DeserializeSceneSnapshot(const std::string& text, SceneSnapshot& outSnapshot) const
{
    const std::size_t namePos = text.find("name=");
    const std::size_t entitiesPos = text.find(";entities=");
    const std::size_t camPos = text.find(";cam=");

    if (namePos != 0 || entitiesPos == std::string::npos || camPos == std::string::npos)
    {
        return false;
    }

    outSnapshot.Name = text.substr(5, entitiesPos - 5);

    const std::string entitiesToken = text.substr(entitiesPos + 10, camPos - (entitiesPos + 10));
    outSnapshot.EntityCount = static_cast<std::size_t>(std::stoul(entitiesToken));

    const std::string camToken = text.substr(camPos + 5);
    std::istringstream camStream(camToken);
    char commaA = 0;
    char commaB = 0;
    if (!(camStream >> outSnapshot.CameraPosition.X >> commaA >> outSnapshot.CameraPosition.Y >> commaB >> outSnapshot.CameraPosition.Z))
    {
        return false;
    }

    return commaA == , && commaB == ,;
}
