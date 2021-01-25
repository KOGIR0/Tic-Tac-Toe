#include "MainMenu.h"

MainMenu::MainMenu(const sf::Vector2f& screenSize)
{
    this->screenSize = screenSize;
    this->offlineBtn = new Button(200, 40, {screenSize.x / 2 - 100, screenSize.y / 2 - 80});
    this->offlineBtn->setFillColor(sf::Color::Green);
    this->offlineTxt = new Text("times-new-roman.ttf", "offline game");

    // put text in center of button
    sf::Vector2f btnSize = this->offlineBtn->getSize();
    sf::Vector2f btnPos = this->offlineBtn->getPosition();
    sf::Vector2f newTxtPos = btnPos + sf::Vector2f({btnSize.x, btnSize.y});
    offlineTxt->setPosition(newTxtPos);

    this->onlineBtn = new Button(200, 40, {screenSize.x / 2 - 100, screenSize.y / 2 + 80});
    this->onlineBtn->setFillColor(sf::Color::Red);
    this->onlineTxt = new Text("times-new-roman.ttf", "online game");

    // set text in center of the button
    btnSize = this->onlineBtn->getSize();
    btnPos = this->onlineBtn->getPosition();
    newTxtPos = btnPos + sf::Vector2f({btnSize.x, btnSize.y});
    onlineTxt->setPosition(newTxtPos);
}

MainMenu::~MainMenu()
{
    delete this->offlineTxt;
    delete this->onlineTxt;
    delete this->offlineBtn;
    delete this->onlineBtn;
}

void MainMenu::resizeMenu(const sf::Vector2f& screenSize)
{
    this->screenSize = screenSize;
    this->offlineBtn->setPosition({screenSize.x / 2 - 100, screenSize.y / 2 - 80});
    sf::Vector2f btnSize = this->offlineBtn->getSize();
    sf::Vector2f btnPos = this->offlineBtn->getPosition();
    sf::Vector2f newTxtPos = btnPos + sf::Vector2f({btnSize.x / 2.0f, btnSize.y / 2.0f});
    offlineTxt->setPosition(newTxtPos);

    this->onlineBtn->setPosition({screenSize.x / 2 - 100, screenSize.y / 2 + 80});
    btnSize = this->onlineBtn->getSize();
    btnPos = this->onlineBtn->getPosition();
    newTxtPos = btnPos + sf::Vector2f({btnSize.x / 2.0f, btnSize.y / 2.0f});
    onlineTxt->setPosition(newTxtPos);
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