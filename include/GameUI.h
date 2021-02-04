#ifndef GAMEUI
#define GAMEUI

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Field.h"
#include "Text.h"
#include "Menu.h"

#define FIELD_PERCENTAGE_X  1.f
#define FIELD_PERCENTAGE_Y  0.9f
#define CELL_NUMBER         3

class GameUI {
public:
    GameUI(const float& screenWidth, const float& screenHeight);
    ~GameUI();
    void drawMainMenu(sf::RenderWindow& window);
    void drawGame(sf::RenderWindow& window);
    void resize(const sf::Vector2u& newSize);
    void reset();
    void setMsg(const std::string& msg);
    // marks cell at given position with sprite with size of a cell
    void markCellWithSprite(const sf::Vector2i& cellPos, const std::string& texturePath);
    int processMenuClick(const sf::Vector2i& clickPos);
    int processOnlineMenuClick(const sf::Vector2i& clickPos);
    bool restartClick(const sf::Vector2i& clickPos);
    // returns whether cell was clicked or no
    bool fieldWasClicked(const sf::Vector2i& cellPos);
    std::vector<std::vector<bool>> getClickedCellsMap();
    sf::Vector2i getCellPosition(const sf::Vector2i& pos);
    int getFieldSize() { return this->ticTacToeField->getSize(); }
    int getFilledCellsNum() { return this->ticTacToeField->getFilledCellsNum(); }

private:
    Field* ticTacToeField;
    Button* restartBtn;
    Text* text;
    Menu* mainMenu;
    Menu* onlineMenu;
};

#endif