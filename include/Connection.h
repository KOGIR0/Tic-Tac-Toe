#include <netinet/in.h>
#include <sstream>
#include <iostream>
#include <unistd.h>

class Connection
{
public:
    Connection(int port);
    ~Connection();
    int recive(std::stringstream& s);
    void send(const std::stringstream& msg);
    void closeConnection();

private:
    int sock;
    struct sockaddr_in addr;
};