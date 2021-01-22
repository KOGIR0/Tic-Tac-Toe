#include "MainMenu.h"

MainMenu::MainMenu(const sf::Vector2f& screenSize)
{
    this->screenSize = screenSize;
    this->offlineBtn = new Button(200, 40, {screenSize.x / 2 - 100, screenSize.y / 2 - 80});
    this->offlineBtn->setFillColor(sf::Color::Green);
    this->offlineTxt = new Text("times-new-roman.ttf", "offline game");
    offlineTxt->setPosition(this->offlineBtn->getPosition() + sf::Vector2f{30, 5});

    this->onlineBtn = new Button(200, 40, {screenSize.x / 2 - 100, screenSize.y / 2 + 80});
    this->onlineBtn->setFillColor(sf::Color::Red);
    this->onlineTxt = new Text("times-new-roman.ttf", "online game");
    onlineTxt->setPosition(this->onlineBtn->getPosition() + sf::Vector2f{30, 5});
}

MainMenu::~MainMenu()
{
    delete this->offlineTxt;
    delete this->onlineTxt;
    delete this->offlineTxt;
    delete this->onlineTxt;
}

void MainMenu::resizeMenu(const sf::Vector2f& screenSize)
{
    this->screenSize = screenSize;
    this->offlineBtn->setPosition({screenSize.x / 2 - 100, screenSize.y / 2 - 80});
    offlineTxt->setPosition(this->offlineBtn->getPosition() + sf::Vector2f{30, 5});

    this->onlineBtn->setPosition({screenSize.x / 2 - 100, screenSize.y / 2 + 80});
    onlineTxt->setPosition(this->onlineBtn->getPosition() + sf::Vector2f{30, 5});
}

// from top to bottom
// returns 1 if first button was clicked
// returns 2 if second
// returns 0 if none was clicked
int MainMenu::processClick(const sf::Vector2i& position)
{
    if(this->offlineBtn->clicked(position))
        return 1;
    if(this->onlineBtn->clicked(position))
        return 2;
    return 0;
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    target.draw(*this->onlineBtn, states);
    target.draw(*this->offlineBtn, states);
    target.draw(*this->offlineTxt, states);
    target.draw(*this->onlineTxt, states);
}