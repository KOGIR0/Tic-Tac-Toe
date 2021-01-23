#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe()
{
    this->menu = new MainMenu({SCREEN_WIDTH, SCREEN_HEIGHT});
    this->status = gameStatus::menu;
    this->fillCellsNum = 0;
    this->playerNum = 0;
    this->victory = false;
    playerSign = { {0, "X"}, {1, "O"} };
    playerName = { {0, "Cross"}, {1, "Nought"} };
    createSymbolMap();

    window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TIC TAK TOE");
    sf::Image icon;
    icon.loadFromFile("X.png");
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    ticTacToeField = new Field(FIELD_PERCENTAGE_X * SCREEN_WIDTH, FIELD_PERCENTAGE_Y * SCREEN_HEIGHT, CELL_NUMBER);

    text = new Text("times-new-roman.ttf", "Cross Turn");
    text->setPosition({this->text->getSize().x / 2.0f ,
        FIELD_PERCENTAGE_Y * SCREEN_HEIGHT + this->text->getSize().y / 2.0f + 5});

    restartBtn = new Button("restartBtn.png", 100.f, SCREEN_HEIGHT * (1.f - FIELD_PERCENTAGE_Y),
        { SCREEN_WIDTH - 100.f, FIELD_PERCENTAGE_Y * SCREEN_HEIGHT });
    restartBtn->setFillColor(sf::Color::White);
}

TicTacToe::~TicTacToe()
{
    delete this->window;
    delete this->ticTacToeField;
    delete this->text;
    delete this->restartBtn;
}

void TicTacToe::updateWindow()
{
    this->window->clear();
    if(this->status == gameStatus::offlineGame)
    {
    this->window->draw(*this->ticTacToeField);
    this->window->draw(*this->text);
    this->window->draw(*this->restartBtn);
    } else if (this->status == gameStatus::menu)
    {
        this->window->draw(*this->menu);
    }
    this->window->display();
}

void TicTacToe::processLeftBtnClick(const sf::Vector2i& mousePos)
{
    if(this->status == gameStatus::offlineGame)
    {
    sf::Vector2f cellPosition = ticTacToeField->getClickedCellIndexes(mousePos);
    if (restartBtn->clicked(mousePos))
    {
        restartBtn->setFillColor(sf::Color(160, 160, 160));
        text->setString("Cross turn");
        this->fillCellsNum = 0;
        this->playerNum = 0;
        this->victory = false;
        createSymbolMap();
        ticTacToeField->clear();
    }
    if (cellPosition.x != -1 && !this->getVictory())
    {
        if (!this->ticTacToeField->cellWasClicked(cellPosition))
        {
            this->fillCellsNum++;
            this->text->setString(playerName[getNextPlayerNum()] + " turn");
            this->setSymbol(cellPosition, playerSign[getPlayerNum()]);
            this->ticTacToeField->markCell(cellPosition.x, cellPosition.y, playerSign[getPlayerNum()] + ".png");
            this->nextPlayer();
        }
        if (checkWinCondition(cellPosition, ticTacToeField->getBoolMap()))
        {
            setVictory(true);
            text->setString(playerName[this->getNextPlayerNum()] + " Won!");
        }
        if (checkDraw() && !this->getVictory())
        {
            setVictory(true);
            text->setString("Draw");
        }
    }
    } else if (this->status == gameStatus::menu)
    {
        int clickResult = this->menu->processClick(mousePos);
        if(clickResult == 1)
        {
            this->status = gameStatus::offlineGame;
        } else if (clickResult == 2)
        {
            this->status = gameStatus::onlineGame;
        }
    }
}

bool TicTacToe::checkDraw()
{
    return fillCellsNum == (map.size() * map.size());
}

void TicTacToe::resizeGameElements(const sf::Event::SizeEvent& es)
{
    window->setView(sf::View(sf::FloatRect(0, 0, es.width, es.height)));
    sf::Vector2u newSize = window->getSize();
    ticTacToeField->setFieldSize(FIELD_PERCENTAGE_X * newSize.x, FIELD_PERCENTAGE_Y * newSize.y);

    text->setPosition({ this->text->getSize().x / 2.0f,
         FIELD_PERCENTAGE_Y * newSize.y + this->text->getSize().y / 2.0f + 5});

    restartBtn->setPosition({ newSize.x - 100.f, FIELD_PERCENTAGE_Y * newSize.y });
    restartBtn->setSize({ 100.f, newSize.y * (1.f - FIELD_PERCENTAGE_Y) });

    this->menu->resizeMenu({ (float)newSize.x, (float)newSize.y });
}

void TicTacToe::process()
{
    sf::Event event;
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
                processLeftBtnClick(mousePos);
            }
            break;
        case sf::Event::MouseButtonReleased:
            restartBtn->setFillColor(sf::Color::White);
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

void TicTacToe::createSymbolMap()
{
    std::vector<symbol> line(CELL_NUMBER);
    std::vector<std::vector<symbol>> newSymbolMap(CELL_NUMBER, line);
    map = newSymbolMap;
}

void TicTacToe::setSymbol(sf::Vector2f position, std::string s)
{
    if (s == "X")
    {
        map[position.x][position.y] = symbol::cross;
    }
    if (s == "O")
    {
        map[position.x][position.y] = symbol::nought;
    }
}

bool TicTacToe::checkWinCondition(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap)
{
    symbol lastSymbol = map[lCkC.x][lCkC.y];
    return checkHorizontalLines(lCkC, boolMap, lastSymbol) || checkVerticalLine(lCkC, boolMap, lastSymbol)
        || checkDiagonals(lCkC, boolMap, lastSymbol);
}

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

bool TicTacToe::checkDiagonals(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol)
{
    // from left upper corner to right bottom corner
    int count = 0;
    for (int i = 0; i < map.size(); i++)
    {
        count = 0;
        for (int j = i, k = 0; j < map[i].size() && k < map[i].size(); j++, k++)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == symbol))
                return true;
        }
        count = 0;
        for (int j = 0, k = i; j < map[i].size() && k < map[i].size(); j++, k++)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == symbol))
                return true;
        }
    }
    // from right upper corner to left bottom corner
    for (int i = 0; i < map.size(); i++)
    {
        count = 0;
        for (int j = i, k = map.size() - 1; j < map.size() && k >= 0; j++, k--)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == symbol))
                return true;
        }
        count = 0;
        for (int j = 0, k = map.size() - 1 - i; j >= 0 && k < map.size(); j++, k--)
        {
            if (checkWinAndIncrement(count, boolMap[j][k] && map[j][k] == symbol))
                return true;
        }
    }
    return false;
}

bool TicTacToe::checkHorizontalLines(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol)
{
    int count = 0;
    for (int j = 0; j < map[lCkC.x].size(); j++)
    {
        if (checkWinAndIncrement(count, boolMap[lCkC.x][j] && map[lCkC.x][j] == symbol))
        return true;
    }
    return false;
}

bool TicTacToe::checkVerticalLine(const sf::Vector2f& lCkC, const std::vector<std::vector<bool>>& boolMap, const symbol& symbol)
{
    int count = 0;
    for (int j = 0; j < map[lCkC.y].size(); j++)
    {
        if (checkWinAndIncrement(count, boolMap[j][lCkC.y] && map[j][lCkC.y] == symbol))
            return true;
    }
    return false;
}