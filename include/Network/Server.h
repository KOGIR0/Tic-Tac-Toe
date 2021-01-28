#ifndef SERVER
#define SERVER

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "Connection.h"
#define PORT 8080

class Server : public Connection
{
public:
    Server();
    virtual void Send(const std::stringstream& s) override;
    virtual int Read(std::stringstream& s) override;
    virtual void Send(const sf::Vector2f& v);
    virtual sf::Vector2f ReadV();

private:
    int server_fd;
    int new_socket;
    struct sockaddr_in address;

};

#endif