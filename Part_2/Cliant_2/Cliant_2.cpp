#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define MULTICAST_GROUP "239.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in addr;
    struct ip_mreq mreq;
    char buffer[BUFFER_SIZE];

    // Step 1: Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Client 2: Error creating socket" << std::endl;
        return -1;
    }

    // Step 2: Set SO_REUSEADDR to allow multiple clients on the same port
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    // Step 3: Bind to the local address and port
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Client 2: Bind failed" << std::endl;
        close(sockfd);
        return -1;
    }

    // Step 4: Join the multicast group
    mreq.imr_multiaddr.s_addr = inet_addr(MULTICAST_GROUP);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
        std::cerr << "Client 2: Failed to join multicast group" << std::endl;
        close(sockfd);
        return -1;
    }

    std::cout << "Client 2: Joined multicast group: " << MULTICAST_GROUP << std::endl;

    // Step 5: Receive messages from the multicast group
    while (true) {
        int len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, nullptr, nullptr);
        if (len < 0) {
            std::cerr << "Client 2: Receive failed" << std::endl;
            break;
        }
        buffer[len] = '\0';
        std::cout << "Client 2 received message: " << buffer << std::endl;
    }

    // Step 6: Leave the multicast group and close the socket
    setsockopt(sockfd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof(mreq));
    close(sockfd);
    return 0;
}
