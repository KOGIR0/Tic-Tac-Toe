#include "GameUI.h"
#include <iostream>

GameUI::GameUI(const float& screenWidth, const float& screenHeight)
{
    std::vector<std::string> btnsTxt = {"pvp game", "pve game"};
    this->mainMenu = std::unique_ptr<Menu>(new Menu({screenWidth, screenHeight}, btnsTxt));
    
    ticTacToeField = std::unique_ptr<Field>(new Field(FIELD_PERCENTAGE_X * screenWidth,
        FIELD_PERCENTAGE_Y * screenHeight, CELL_NUMBER));

    text = std::unique_ptr<Text>(new Text("times-new-roman.ttf", "Cross Turn"));
    text->setPosition({this->text->getSize().x / 2.0f ,
        FIELD_PERCENTAGE_Y * screenHeight + this->text->getSize().y / 2.0f + 5});

    restartBtn = std::unique_ptr<Button>(new Button("restartBtn.png",
        100.f, screenHeight * (1.f - FIELD_PERCENTAGE_Y),
        { screenWidth - 100.f, FIELD_PERCENTAGE_Y * screenHeight }));
    restartBtn->setFillColor(sf::Color::White);
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

sf::Vector2i GameUI::getCellPosition(const sf::Vector2i& pos)
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

void GameUI::markCellWithSprite(const sf::Vector2i& cellPos, const std::string& texturePath)
{
    this->ticTacToeField->markCell(cellPos.x, cellPos.y, texturePath);
}

bool GameUI::restartClick(const sf::Vector2i& clickPos)
{
    return this->restartBtn->clicked(clickPos);
}

bool GameUI::fieldWasClicked(const sf::Vector2i& cellPos)
{
    return this->ticTacToeField->cellWasClicked(cellPos);
}

void GameUI::setMsg(const std::string& msg)
{
    this->text->setString(msg);
}

void GameUI::resize(const sf::Vector2u& newSize)
{
    this->ticTacToeField->setFieldSize(FIELD_PERCENTAGE_X * newSize.x, FIELD_PERCENTAGE_Y * newSize.y);

    text->setPosition({ this->text->getSize().x / 2.0f,
         FIELD_PERCENTAGE_Y * newSize.y + this->text->getSize().y / 2.0f + 5});

    restartBtn->setPosition({ newSize.x - 100.f, FIELD_PERCENTAGE_Y * newSize.y });
    restartBtn->setSize({ 100.f, newSize.y * (1.f - FIELD_PERCENTAGE_Y) });

    this->mainMenu->resizeMenu({ (float)newSize.x, (float)newSize.y });
}