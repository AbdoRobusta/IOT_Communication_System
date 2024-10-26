#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

class TCPServer {
private:
    int serverSockfd, clientSockfd;
    struct sockaddr_in serverAddr, clientAddr;

public:
    TCPServer(int port) {
        serverSockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSockfd < 0) {
            throw std::runtime_error("Error creating server socket");
        }

        memset(&serverAddr, 0, sizeof(serverAddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(port);

        if (bind(serverSockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
            throw std::runtime_error("Error binding socket");
        }

        listen(serverSockfd, 5);
    }

    void acceptClient() {
        socklen_t len = sizeof(clientAddr);
        clientSockfd = accept(serverSockfd, (struct sockaddr*)&clientAddr, &len);
        if (clientSockfd < 0) {
            throw std::runtime_error("Error accepting client");
        }
        std::cout << "Client connected!" << std::endl;
    }

    void receiveAndRespond() {
        char buffer[1024] = {0};
        recv(clientSockfd, buffer, sizeof(buffer), 0);
        std::cout << "Received: " << buffer << std::endl;

        std::string response = "Acknowledgment. Current Temperature is 39°C.";
        send(clientSockfd, response.c_str(), response.size(), 0);
    }

    void shutdown() {
        close(clientSockfd);
        close(serverSockfd);
    }

    ~TCPServer() {
        shutdown();
    }
};

#endif
