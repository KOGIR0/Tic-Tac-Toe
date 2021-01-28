#ifndef CONNECTION
#define CONNECTION

#include <string.h>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

class Connection
{
public:
    virtual ~Connection(){};
    virtual void Send(const std::stringstream& s) = 0;
    virtual int Read(std::stringstream& s) = 0;
    virtual void Send(const sf::Vector2f& v) = 0;
    virtual sf::Vector2f ReadV() = 0;
};

#endif