#ifndef TIKTAKTOE
#define TIKTAKTOE

#include <vector>
#include <memory>
#include "Field.h"
#include "SFML/Graphics.hpp"
#include "Text.h"
#include "GameUI.h"
#include "GameResources.h"

#define SCREEN_WIDTH        500.f
#define SCREEN_HEIGHT       600.f
#define MAX_PLAYER_NUM      2
#define CELLS_TO_WIN        3

class TicTacToe
{
public:
    TicTacToe();
    bool isRunning();
    void process();
    void updateWindow();

private:
    GameResources resources;
    std::unique_ptr<sf::RenderWindow> window;
    GameUI game_ui;

    void setSymbol(sf::Vector2i cellPos, std::string s);
    bool checkWinCondition(const sf::Vector2i& lCkC);
    bool checkDraw();
    void resizeGameElements(const sf::Event::SizeEvent &newSize);
    void processLeftBtnClick(sf::Vector2i& cellPos);
    sf::Vector2i processAIturn();
    bool tryTurn(sf::Vector2i turn, const symbol& s);
    void processFieldClick(const sf::Vector2i& cellPos);
    bool checkWinAndIncrement(int& num, const bool& condition);
    bool checkDiagonals(const sf::Vector2i& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
    bool checkHorizontalLines(const sf::Vector2i& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
    bool checkVerticalLine(const sf::Vector2i& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
};

#endif