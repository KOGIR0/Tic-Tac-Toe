#include "Connection.h"

Connection::Connection(int port)
{
    this->sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(this->sock < 0)
    {
        std::cerr << "socket" << std::endl;
    }
    this->addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(this->sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cerr << "binding" << std::endl;
    }
}

int Connection::recive(std::stringstream& s)
{
    char buf[1024];
    int bytes_read = recvfrom(this->sock, buf, 1024, 0, NULL, NULL);
    buf[bytes_read] = '\0';
    s << buf;
    return bytes_read;
}

void Connection::send(const std::stringstream& msg)
{
    sendto(this->sock, msg.str().c_str(), msg.str().size(), 0,
        (struct sockaddr *)&this->addr, sizeof(addr));
}