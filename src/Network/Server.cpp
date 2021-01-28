#include "Server.h"

Server::Server()
{
    int opt = 1;
    int addrlen = sizeof(this->address);
    if ((this->server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if(setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
        &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(PORT);
    if(bind(this->server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if(listen(this->server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if((this->new_socket = accept(this->server_fd, (struct sockaddr*)&address,
        (socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}

void Server::Send(const std::stringstream& s)
{
    send(this->new_socket, s.str().c_str(), s.str().size(), 0);
}

int Server::Read(std::stringstream& s)
{
    char buffer[1024];
    int valread = read(this->new_socket, buffer, 1024);
    buffer[valread] = '\0';
    s << buffer;
    return valread;
}

void Server::Send(const sf::Vector2f& v)
{
    std::stringstream s;
    s << " " << v.x << " " << v.y;
    this->Send(s);
}

sf::Vector2f Server::ReadV()
{
    std::stringstream s;
    int valread = this->Read(s);
    float x, y;
    s >> x >> y;
    return {x, y};
}