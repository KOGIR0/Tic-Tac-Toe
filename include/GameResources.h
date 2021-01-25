#ifndef GAME_RESOURCES
#define GAME_RESOURCES

#include <map>
#include <vector>
#include "Text.h"
#include "Field.h"
#include "MainMenu.h"
#include "Button.h"

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

enum class gameStatus
{
    menu,
    onlineGame,
    offlineGame
};

class GameResources
{
public:
    GameResources();
    bool getVictory() { return victory; }
    int getNextPlayerNum() { return (this->playerNum + 1) % MAX_PLAYER_NUM; }
    void setVictory(const bool& v) { this->victory = v; }
    void nextPlayer() { this->playerNum = (this->playerNum + 1) % MAX_PLAYER_NUM; }
    void reset();
    void setStatus(const gameStatus& s);
    void setSymbolMap(const std::vector<std::vector<symbol>>& m);
    void increaseFilledCellsNum() { this->fillCellsNum++; }
    std::string getCurPlayerStr() { return this->playerName[this->playerNum]; }
    std::string getNextPlayerStr() { return this->playerName[getNextPlayerNum()]; }
    std::string getCurPlayerSybmol() { return this->playerSign[this->playerNum]; }
    gameStatus getStatus() { return this->status; }
    std::vector<std::vector<symbol>> getSymbolMap() { return this->map; }

private:
    int playerNum;
    bool victory;
    int fillCellsNum;
    gameStatus status;
    std::vector<std::vector<symbol>> map;
    std::map<int, std::string> playerSign;
    std::map<int, std::string> playerName;
};

#endif