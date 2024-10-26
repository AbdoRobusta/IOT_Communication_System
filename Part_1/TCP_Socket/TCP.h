#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include "Socket.h"
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

class TCPSocket : public Socket {
private:
    int sockfd;
    struct sockaddr_in addr;

public:
    TCPSocket(const std::string& ip, int port) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            throw std::runtime_error("Error creating TCP socket");
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);
    }

    void connect() override {
        if (::connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
            throw std::runtime_error("Error connecting to server");
        }
    }

    void send(const std::string& message) override {
        ::send(sockfd, message.c_str(), message.size(), 0);
    }

    void receive() override {
        char buffer[1024] = {0};
        recv(sockfd, buffer, sizeof(buffer), 0);
        std::cout << "Received: " << buffer << std::endl;
    }

    void shutdown() override {
        close(sockfd);
    }

    ~TCPSocket() {
        shutdown();
    }
};

#endif
