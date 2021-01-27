#include "GameUI.h"
#include <iostream>

GameUI::GameUI(const float& screenWidth, const float& screenHeight)
{
    std::vector<std::string> btnsTxt = {"offline game", "online game"};
    this->mainMenu = new Menu({screenWidth, screenHeight}, btnsTxt);

    btnsTxt = {"server", "client"};
    this->onlineMenu = new Menu({screenWidth, screenHeight}, btnsTxt);
    
    ticTacToeField = new Field(FIELD_PERCENTAGE_X * screenWidth,
        FIELD_PERCENTAGE_Y * screenHeight, CELL_NUMBER);

    text = new Text("times-new-roman.ttf", "Cross Turn");
    text->setPosition({this->text->getSize().x / 2.0f ,
        FIELD_PERCENTAGE_Y * screenHeight + this->text->getSize().y / 2.0f + 5});

    restartBtn = new Button("restartBtn.png", 100.f, screenHeight * (1.f - FIELD_PERCENTAGE_Y),
        { screenWidth - 100.f, FIELD_PERCENTAGE_Y * screenHeight });
    restartBtn->setFillColor(sf::Color::White);
}

GameUI::~GameUI()
{
    delete this->mainMenu;
    delete this->restartBtn;
    delete this->text;
    delete this->ticTacToeField;
}

void GameUI::drawGame(sf::RenderWindow& window)
{
    window.draw(*this->ticTacToeField);
    window.draw(*this->text);
    window.draw(*this->restartBtn);
}

void GameUI::drawMainMenu(sf::RenderWindow& window)
{
    window.draw(*this->mainMenu);
}

void GameUI::drawOnlineMenu(sf::RenderWindow& window)
{
    window.draw(*this->onlineMenu);
}

sf::Vector2f GameUI::getCellPosition(const sf::Vector2i& pos)
{
    return this->ticTacToeField->getClickedCellIndexes(pos);
}

void GameUI::reset()
{
    this->restartBtn->setFillColor(sf::Color(160, 160, 160));
    this->text->setString("Cross turn");
    this->ticTacToeField->clear();
}

int GameUI::processMenuClick(const sf::Vector2i& clickPos)
{
    return this->mainMenu->processClick(clickPos);
}

int GameUI::processOnlineMenuClick(const sf::Vector2i& clickPos)
{
    return this->onlineMenu->processClick(clickPos);
}

std::vector<std::vector<bool>> GameUI::getClickedCellsMap()
{
    return this->ticTacToeField->getBoolMap();
}

void GameUI::markCellWithSprite(const sf::Vector2f& cellPos, const std::string& texturePath)
{
    this->ticTacToeField->markCell(cellPos.x, cellPos.y, texturePath);
}

bool GameUI::restartClick(const sf::Vector2i& clickPos)
{
    return this->restartBtn->clicked(clickPos);
}

bool GameUI::fieldWasClicked(const sf::Vector2f& cellPos)
{
    return this->ticTacToeField->cellWasClicked(cellPos);
}

void GameUI::setMsg(const std::string& msg)
{
    this->text->setString(msg);
}

void GameUI::resize(const sf::Vector2u& newSize)
{
    std::cout << "Resize Start" << std::endl;
    this->ticTacToeField->setFieldSize(FIELD_PERCENTAGE_X * newSize.x, FIELD_PERCENTAGE_Y * newSize.y);

    text->setPosition({ this->text->getSize().x / 2.0f,
         FIELD_PERCENTAGE_Y * newSize.y + this->text->getSize().y / 2.0f + 5});

    restartBtn->setPosition({ newSize.x - 100.f, FIELD_PERCENTAGE_Y * newSize.y });
    restartBtn->setSize({ 100.f, newSize.y * (1.f - FIELD_PERCENTAGE_Y) });

    this->mainMenu->resizeMenu({ (float)newSize.x, (float)newSize.y });
    this->onlineMenu->resizeMenu({ (float)newSize.x, (float)newSize.y });
}