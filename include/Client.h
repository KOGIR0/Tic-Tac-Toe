#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <iostream>
#define PORT 8080

class Client
{
public:
    Client();
    void Send(const std::stringstream& s);
    int Read(std::stringstream& s);

private:
    int sock;
    struct sockaddr_in serv_addr;
};