#include <netinet/in.h>
#include <sstream>
#include <iostream>

class Connection
{
public:
    Connection(int port);
    int recive(std::stringstream& s);
    void send(const std::stringstream& msg);

private:
    int sock;
    struct sockaddr_in addr;
};