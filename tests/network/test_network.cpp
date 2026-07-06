#include "../../Engine/Network/Network.h"

void run_network_tests() {
    Network net;

    std::string msg = "hello";
    net.Send(msg);

    report("Network Queue", net.HasMessages());
}
