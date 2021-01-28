#include "Client.h"

Client::Client()
{
    if((this->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creationg error \n");
        return;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return;
    }
}

void Client::Send(const std::stringstream& s)
{
    send(sock, s.str().c_str(), s.str().size(), 0);
}

int Client::Read(std::stringstream& s)
{
    char buffer[1024];
    int valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    s << buffer;
    return valread;
}

void Client::Send(const sf::Vector2f& v)
{
    std::stringstream s;
    s << " " << v.x << " " << v.y;
    this->Send(s);
}

sf::Vector2f Client::ReadV()
{
    std::stringstream s;
    int valread = this->Read(s);
    float x, y;
    s >> x >> y;
    return {x, y};
}