#include "../UDP_Socket/UDP_Socket.h"
#include <thread>
#include <chrono>

int main() {
    try {
        UDPSocket server("239.0.0.1", 8080);
        while (true) {
            server.send("System update at 10:00 AM");
            std::cout << "Multicast message sent." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
