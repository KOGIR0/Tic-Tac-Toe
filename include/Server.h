#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sstream>
#include <iostream>
#define PORT 8080

class Server
{
public:
    Server();
    void Send(const std::stringstream& s);
    int Read(std::stringstream& s);

private:
    int server_fd;
    int new_socket;
    struct sockaddr_in address;

};