#pragma once

#include "Engine/Serialization/Serializer.h"

#include <queue>
#include <string>

struct NetworkMessage
{
    std::string Payload;
};

class NetworkingLayer
{
public:
    bool Connect(const std::string& endpoint);
    bool IsConnected() const;

    void Send(const std::string& payload);
    bool Poll(NetworkMessage& outMessage);

    std::string ReplicateState(const SceneSnapshot& snapshot) const;

private:
    bool bConnected = false;
    std::string Endpoint;
    std::queue<NetworkMessage> Queue{};
    Serializer SnapshotSerializer{};
};
