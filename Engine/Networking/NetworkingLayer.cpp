#include "NetworkingLayer.h"

bool NetworkingLayer::Connect(const std::string& endpoint)
{
    Endpoint = endpoint;
    bConnected = !Endpoint.empty();
    return bConnected;
}

bool NetworkingLayer::IsConnected() const
{
    return bConnected;
}

void NetworkingLayer::Send(const std::string& payload)
{
    if (!bConnected)
    {
        return;
    }

    Queue.push(NetworkMessage{payload});
}

bool NetworkingLayer::Poll(NetworkMessage& outMessage)
{
    if (Queue.empty())
    {
        return false;
    }

    outMessage = Queue.front();
    Queue.pop();
    return true;
}

std::string NetworkingLayer::ReplicateState(const SceneSnapshot& snapshot) const
{
    return SnapshotSerializer.SerializeSceneSnapshot(snapshot);
}
