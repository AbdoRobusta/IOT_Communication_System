#include "../TCP_Socket/TCP.h"

int main() {
    try {
        TCPSocket client("127.0.0.1", 8080);
        client.connect();
        client.send("Hello, Server!");
        client.receive();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
