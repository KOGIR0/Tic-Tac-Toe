#include "GameResources.h"

GameResources::GameResources()
{
    this->status = gameStatus::menu;
    this->fillCellsNum = 0;
    this->playerNum = 0;
    this->victory = false;
    playerSign = { {0, "X"}, {1, "O"} };
    playerName = { {0, "Cross"}, {1, "Nought"} };
    std::vector<symbol> line(CELL_NUMBER);
    std::vector<std::vector<symbol>> newSymbolMap(CELL_NUMBER, line);
    this->map = newSymbolMap;
}

void GameResources::setSymbolMap(const std::vector<std::vector<symbol>>& m)
{
    this->map = m;
}

void GameResources::setStatus(const gameStatus& s)
{
    this->status = s;
}

void GameResources::reset()
{
    this->fillCellsNum = 0;
    this->playerNum = 0;
    this->victory = false;
    std::vector<symbol> line(CELL_NUMBER);
    std::vector<std::vector<symbol>> newSymbolMap(CELL_NUMBER, line);
    this->map = newSymbolMap;
}