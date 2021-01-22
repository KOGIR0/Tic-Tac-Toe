#ifndef TIKTAKTOE
#define TIKTAKTOE

#include "Field.h"
#include "SFML/Graphics.hpp"
#include "Text.h"
#include <vector>

#define SCREEN_WIDTH        500.f
#define SCREEN_HEIGHT       600.f
#define FIELD_PERCENTAGE_X  1.f
#define FIELD_PERCENTAGE_Y  0.9f
#define CELL_NUMBER         3
#define MAX_PLAYER_NUM      2
#define CELLS_TO_WIN        3

enum class symbol
{
    cross,
    nought
};

class TicTacToe
{
public:
    TicTacToe();
    ~TicTacToe();
    bool isRunning();
    void process();
    void updateWindow();

private:
    int playerNum;
    bool victory;
    int fillCellsNum;
    std::vector<std::vector<symbol>> map;
    std::map<int, std::string> playerSign;
    std::map<int, std::string> playerName;

    sf::RenderWindow* window;
    Field* ticTacToeField;
    Button* restartBtn;
    Text* text;

    void setSymbol(sf::Vector2f position, std::string s);
    bool checkWinCondition(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap);
    bool getVictory() { return victory; }
    int getPlayerNum() { return this->playerNum; }
    int getNextPlayerNum() { return (this->playerNum + 1) % MAX_PLAYER_NUM; }
    void setVictory(bool v) { this->victory = v; }
    void nextPlayer() { this->playerNum = (this->playerNum + 1) % MAX_PLAYER_NUM; }

    bool checkDraw();
    void resizeGameElements(const sf::Event::SizeEvent &newSize);
    void processLeftBtnClick(const sf::Vector2i& mousePos);
    void createSymbolMap();
    bool checkWinAndIncrement(int& num, const bool& condition);
    bool checkDiagonals(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
    bool checkHorizontalLines(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
    bool checkVerticalLine(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol);
};

#endif