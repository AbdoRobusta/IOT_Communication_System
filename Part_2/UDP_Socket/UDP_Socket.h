#ifndef UDPSOCKET_HPP
#define UDPSOCKET_HPP

#include "Socket.h"
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

class UDPSocket : public Socket {
private:
    int sockfd;
    struct sockaddr_in addr;

public:
    UDPSocket(const std::string& ip, int port) {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            throw std::runtime_error("Error creating UDP socket");
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
    }

    void send(const std::string& message) override {
        sendto(sockfd, message.c_str(), message.size(), 0, (struct sockaddr*)&addr, sizeof(addr));
    }

    void connect() override {}
    void receive() override {}
    void shutdown() override {
        close(sockfd);
    }

    ~UDPSocket() {
        shutdown();
    }
};

#endif
