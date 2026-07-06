#include "../../Engine/Serialization/Serializer.h"

void run_serialization_tests() {
    SceneSnapshot snap;
    snap.Name = "TestScene";
    snap.EntityCount = 3;

    std::string out = Serializer::Serialize(snap);

    report("Serialization Contains Name",
        out.find("TestScene") != std::string::npos);

    report("Serialization Contains Count",
        out.find("3") != std::string::npos);
}
