#ifndef TIKTAKTOE
#define TIKTAKTOE

#include "Field.h"
#include "SFML/Graphics.hpp"
#include "Text.h"
#include <vector>
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
    ~TicTacToe();
    bool isRunning();
    void process();
    void updateWindow();

private:
    GameResources resources;
    sf::RenderWindow* window;
    GameUI* game_ui;
    Connection* connection;

    void setSymbol(sf::Vector2f position, std::string s);
    bool checkWinCondition(const sf::Vector2f& lCkC);

    bool checkDraw();
    void resizeGameElements(const sf::Event::SizeEvent &newSize);
    void processLeftBtnClick(sf::Vector2f& cellPos);
    void processLeftBtnOfflineGame(sf::Vector2f& cellPos);
    void processLeftBtnClient(sf::Vector2f& cellPos);
    void processFieldClick(const sf::Vector2f& cellPos);
    // server is also a player
    void processLeftBtnServer(sf::Vector2f& cellPos);
    bool checkWinAndIncrement(int& num, const bool& condition);
    bool checkDiagonals(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
    bool checkHorizontalLines(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
    bool checkVerticalLine(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
};

#endif