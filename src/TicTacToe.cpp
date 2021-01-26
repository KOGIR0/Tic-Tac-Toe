#include "TicTacToe.h"
#include "GameResources.h"
#include <iostream>

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

void TicTacToe::updateWindow()
{
    this->window->clear();
    gameStatus s = this->resources.getStatus();
    if(s == gameStatus::offlineGame || s == gameStatus::onlineGame)
    {
        this->game_ui->drawGame(*this->window);
    } else if (s == gameStatus::menu)
    {
        this->game_ui->drawMenu(*this->window);
    }
    this->window->display();
}

void TicTacToe::processLeftBtnClick(const sf::Vector2i& mousePos)
{
    gameStatus s = this->resources.getStatus();
    if(s == gameStatus::onlineGame)
    {
        sf::Vector2f cellPosition = this->game_ui->getCellPosition(mousePos);
        if (this->game_ui->restartClick(mousePos))
        {
            this->resources.reset();
            this->game_ui->reset();
        }
        if (cellPosition.x != -1 && !this->resources.getVictory())
        {
            if (!this->game_ui->fieldWasClicked(cellPosition))
            {
                this->resources.increaseFilledCellsNum();
                this->game_ui->setMsg(this->resources.getNextPlayerStr() + " turn");
                this->setSymbol(cellPosition, this->resources.getCurPlayerSybmol());
                this->game_ui->markCellWithSprite(cellPosition, this->resources.getCurPlayerSybmol() + ".png");
                this->resources.nextPlayer();
            }
            if (checkWinCondition(cellPosition))
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
    } else if (s == gameStatus::offlineGame)
    {
        sf::Vector2f cellPosition = this->game_ui->getCellPosition(mousePos);
        if (this->game_ui->restartClick(mousePos))
        {
            this->resources.reset();
            this->game_ui->reset();
        }
        if (cellPosition.x != -1 && !this->resources.getVictory())
        {
            if (!this->game_ui->fieldWasClicked(cellPosition))
            {
                this->resources.increaseFilledCellsNum();
                this->game_ui->setMsg(this->resources.getNextPlayerStr() + " turn");
                this->setSymbol(cellPosition, this->resources.getCurPlayerSybmol());
                this->game_ui->markCellWithSprite(cellPosition, this->resources.getCurPlayerSybmol() + ".png");
                this->resources.nextPlayer();
            }
            if (checkWinCondition(cellPosition))
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
    } else if (s == gameStatus::menu)
    {
        int clickResult = this->game_ui->processMenuClick(mousePos);
        if(clickResult == 1)
        {
            this->resources.setStatus(gameStatus::offlineGame);
        } else if (clickResult == 2)
        {
            this->resources.setStatus(gameStatus::onlineGame);
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
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            std::cout << "Closing window" << std::endl;
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = { event.mouseButton.x, event.mouseButton.y };
                processLeftBtnClick(mousePos);
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
}

bool TicTacToe::isRunning()
{
    return this->window->isOpen();
}

void TicTacToe::setSymbol(sf::Vector2f position, std::string s)
{
    std::vector<std::vector<symbol>> map = this->resources.getSymbolMap();
    if (s == "X")
    {
        map[position.x][position.y] = symbol::cross;
    }
    if (s == "O")
    {
        map[position.x][position.y] = symbol::nought;
    }
    this->resources.setSymbolMap(map);
}

bool TicTacToe::checkWinCondition(const sf::Vector2f& lCkC)
{
    std::vector<std::vector<symbol>> map = this->resources.getSymbolMap();
    std::vector<std::vector<bool>> boolMap = this->game_ui->getClickedCellsMap();
    symbol lastSymbol = map[lCkC.x][lCkC.y];
    return checkHorizontalLines(lCkC, boolMap, lastSymbol) || checkVerticalLine(lCkC, boolMap, lastSymbol)
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

bool TicTacToe::checkDiagonals(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& s)
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

bool TicTacToe::checkHorizontalLines(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& s)
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

bool TicTacToe::checkVerticalLine(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& s)
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