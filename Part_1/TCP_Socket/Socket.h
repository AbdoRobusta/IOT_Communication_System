#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>

class Socket {
public:
    virtual ~Socket() {}
    virtual void connect() = 0;
    virtual void send(const std::string& message) = 0;
    virtual void receive() = 0;
    virtual void shutdown() = 0;
};

#endif
