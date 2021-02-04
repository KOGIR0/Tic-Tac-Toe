#include "TicTacToe.h"
#include "GameResources.h"
#include <iostream>
#include <thread>

TicTacToe::TicTacToe()
{
    game_ui = new GameUI(SCREEN_WIDTH, SCREEN_HEIGHT);
    window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TIC TAK TOE");
    sf::Image icon;
    icon.loadFromFile("X.png");
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

TicTacToe::~TicTacToe()
{
    delete this->window;
    delete this->game_ui;
}

bool TicTacToe::tryTurn(sf::Vector2i turn, const symbol& s)
{
    std::vector<std::vector<symbol>> prevMap = resources.getSymbolMap();
    std::vector<std::vector<bool>> prevClickMap = game_ui->getClickedCellsMap();
    if(!prevClickMap[turn.x][turn.y])
    {
        std::vector<std::vector<bool>> newClickMap = prevClickMap;
        newClickMap[turn.x][turn.y] = true;
        std::vector<std::vector<symbol>> newMap = prevMap;
        newMap[turn.x][turn.y] = s;
        this->resources.setSymbolMap(newMap);
        
        if(checkDiagonals(turn, newClickMap, s) ||
            checkHorizontalLines(turn, newClickMap, s) ||
            checkVerticalLine(turn, newClickMap, s))
        {
            return true;
        }
        this->resources.setSymbolMap(prevMap);
    }
    return false;
}

sf::Vector2i TicTacToe::processAIturn()
{
    std::vector<std::vector<symbol>> prevMap = resources.getSymbolMap();
    std::vector<std::vector<bool>> prevClickMap = game_ui->getClickedCellsMap();
    // look for a turn to win a game
    for(int i = 0; i < prevMap.size(); i++)
    {
        for(int j = 0; j < prevMap.size(); j++)
        {
            if(tryTurn({i, j}, symbol::nought))
            {
                return {i, j};
            }
        }
    }
    // look for a turn to prevent other player win
    for(int i = 0; i < prevMap.size(); i++)
    {
        for(int j = 0; j < prevMap.size(); j++)
        {
            if(tryTurn({i, j}, symbol::cross))
            {
                return {i, j};
            }
        }
    }
    // look for any turn
    for(int i = 0; i < prevMap.size(); i++)
    {
        for(int j = 0; j < prevMap.size(); j++)
        {
            if(!prevClickMap[i][j])
            {
                this->setSymbol({i, j}, this->resources.getCurPlayerSybmol());
                return {i, j};
            }
        }
    }
    // make turn in center
    sf::Vector2i centerCell = {(int)prevMap.size() / 2, (int)prevMap.size() / 2};
    if(!prevClickMap[centerCell.x][centerCell.y])
    {
        return centerCell;
    }
    return {-1, -1};
}

void TicTacToe::updateWindow()
{
    this->window->clear();
    gameStatus s = this->resources.getStatus();
    if(s == gameStatus::pvp || s == gameStatus::pve)
    {
        this->game_ui->drawGame(*this->window);
    } else if (s == gameStatus::menu)
    {
        this->game_ui->drawMainMenu(*this->window);
    }
    this->window->display();
}

void TicTacToe::processFieldClick(const sf::Vector2i& cellPos)
{
    if (!this->game_ui->fieldWasClicked(cellPos))
    {
        this->resources.increaseFilledCellsNum();
        this->game_ui->setMsg(this->resources.getNextPlayerStr() + " turn");
        this->setSymbol(cellPos, this->resources.getCurPlayerSybmol());
        this->game_ui->markCellWithSprite(cellPos, this->resources.getCurPlayerSybmol() + ".png");
        this->resources.nextPlayer();
    }
}

void TicTacToe::processLeftBtnClick(sf::Vector2i& cellPos)
{
    gameStatus s = this->resources.getStatus();
    switch(s)
    {
    case (gameStatus::pvp):
        this->processFieldClick(cellPos);
        break;
    case (gameStatus::pve):
        if(this->resources.getCurPlayerSybmol() == "X")
        {
            this->processFieldClick(cellPos);
        }
    }
}

bool TicTacToe::checkDraw()
{
    return this->game_ui->getFilledCellsNum() == this->game_ui->getFieldSize();
}

void TicTacToe::resizeGameElements(const sf::Event::SizeEvent& es)
{
    this->window->setView(sf::View(sf::FloatRect(0, 0, es.width, es.height)));
    sf::Vector2u newSize = window->getSize();
    this->game_ui->resize(newSize);
}

void TicTacToe::process()
{
    sf::Event event;
    sf::Vector2i cellPos;
    gameStatus s = this->resources.getStatus();
    if(s == gameStatus::pve && !this->resources.getVictory() && this->resources.getCurPlayerSybmol() == "O")
    {
        cellPos = this->processAIturn();
        this->processFieldClick(cellPos);
    }
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = { event.mouseButton.x, event.mouseButton.y };
                if (s == gameStatus::menu)
                {
                    int clickResult = this->game_ui->processMenuClick(mousePos);
                    if(clickResult == 1)
                    {
                        this->resources.setStatus(gameStatus::pvp);
                    } else if (clickResult == 2)
                    {
                        this->resources.setStatus(gameStatus::pve);
                    }
                } else if(s == gameStatus::pvp || s == gameStatus::pve){
                    cellPos = this->game_ui->getCellPosition(mousePos); 
                    if (this->game_ui->restartClick(mousePos))
                    {
                        this->resources.reset();
                        this->game_ui->reset();
                    } else if(cellPos.x != -1 && !this->resources.getVictory())
                    {
                        if(this->resources.getCurPlayerSybmol() == "X" || s == gameStatus::pvp)
                            this->processLeftBtnClick(cellPos);
                    }
                }
            }
            break;
        case sf::Event::MouseButtonReleased:
            //restartBtn->setFillColor(sf::Color::White);
            break;
        case sf::Event::Resized:
            this->resizeGameElements(event.size);
            break;
        }
    }
    if (cellPos.x != -1 && checkWinCondition(cellPos))
    {
        this->resources.setVictory(true);
        this->game_ui->setMsg(this->resources.getNextPlayerStr() + " Won!");
    }
    if (checkDraw() && !this->resources.getVictory())
    {
        this->resources.setVictory(true);
        this->game_ui->setMsg("Draw");
    }
}

bool TicTacToe::isRunning()
{
    return this->window->isOpen();
}

void TicTacToe::setSymbol(sf::Vector2i cellPos, std::string s)
{
    std::vector<std::vector<symbol>> map = this->resources.getSymbolMap();
    if (s == "X")
    {
        map[cellPos.x][cellPos.y] = symbol::cross;
    }
    if (s == "O")
    {
        map[cellPos.x][cellPos.y] = symbol::nought;
    }
    this->resources.setSymbolMap(map);
}

bool TicTacToe::checkWinCondition(const sf::Vector2i& lCkC)
{
    std::vector<std::vector<symbol>> map = this->resources.getSymbolMap();
    std::vector<std::vector<bool>> boolMap = this->game_ui->getClickedCellsMap();
    symbol lastSymbol = map[lCkC.x][lCkC.y];
    return checkHorizontalLines(lCkC, boolMap, lastSymbol)
        || checkVerticalLine(lCkC, boolMap, lastSymbol)
        || checkDiagonals(lCkC, boolMap, lastSymbol);
}

// helper function
bool TicTacToe::checkWinAndIncrement(int& num, const bool& condition)
{
    if (condition)
    {
        num++;
        if (num == CELLS_TO_WIN)
        {
            return true;
        }
    }
    else {
        num = 0;
    }
    return false;
}

bool TicTacToe::checkDiagonals(const sf::Vector2i& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& s)
{
    std::vector<std::vector<symbol>> map = this->resources.getSymbolMap();
    // from left upper corner to right bottom corner
    int count = 0;
    for (int i = 0; i < map.size(); i++)
    {
        count = 0;
        for (int j = i, k = 0; j < map[i].size() && k < map[i].size(); j++, k++)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == s))
                return true;
        }
        count = 0;
        for (int j = 0, k = i; j < map[i].size() && k < map[i].size(); j++, k++)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == s))
                return true;
        }
    }
    // from right upper corner to left bottom corner
    for (int i = 0; i < map.size(); i++)
    {
        count = 0;
        for (int j = i, k = map.size() - 1; j < map.size() && k >= 0; j++, k--)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == s))
                return true;
        }
        count = 0;
        for (int j = 0, k = map.size() - 1 - i; j >= 0 && k < map.size(); j++, k--)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == s))
                return true;
        }
    }
    return false;
}

bool TicTacToe::checkHorizontalLines(const sf::Vector2i& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& s)
{
    std::vector<std::vector<symbol>> map = this->resources.getSymbolMap();
    int count = 0;
    for (int j = 0; j < map[lCkC.x].size(); j++)
    {
        if (checkWinAndIncrement(count, boolMap[lCkC.x][j] && map[lCkC.x][j] == s))
        return true;
    }
    return false;
}

bool TicTacToe::checkVerticalLine(const sf::Vector2i& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& s)
{
    std::vector<std::vector<symbol>> map = this->resources.getSymbolMap();
    int count = 0;
    for (int j = 0; j < map[lCkC.y].size(); j++)
    {
        if (checkWinAndIncrement(count, boolMap[j][lCkC.y] && map[j][lCkC.y] == s))
            return true;
    }
    return false;
}