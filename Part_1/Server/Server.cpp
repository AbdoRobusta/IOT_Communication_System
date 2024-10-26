#include "../TCP_Socket/TCP_Server.h"

int main() {
    try {
        TCPServer server(8080);
        server.acceptClient();
        server.receiveAndRespond();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
