#ifndef CLIENT
#define CLIENT

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "Connection.h"
#define PORT 8080

class Client : public Connection
{
public:
    Client();
    virtual void Send(const std::stringstream& s) override;
    virtual int Read(std::stringstream& s) override;
    virtual void Send(const sf::Vector2f& v);
    virtual sf::Vector2f ReadV();

private:
    int sock;
    struct sockaddr_in serv_addr;
};

#endif