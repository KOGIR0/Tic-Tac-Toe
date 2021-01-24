#include "GameResources.h"

GameResources::GameResources()
{
    this->menu = new MainMenu({SCREEN_WIDTH, SCREEN_HEIGHT});
    this->status = gameStatus::menu;
    this->fillCellsNum = 0;
    this->playerNum = 0;
    this->victory = false;
    playerSign = { {0, "X"}, {1, "O"} };
    playerName = { {0, "Cross"}, {1, "Nought"} };

    
    ticTacToeField = new Field(FIELD_PERCENTAGE_X * SCREEN_WIDTH, FIELD_PERCENTAGE_Y * SCREEN_HEIGHT, CELL_NUMBER);

    text = new Text("times-new-roman.ttf", "Cross Turn");
    text->setPosition({this->text->getSize().x / 2.0f ,
        FIELD_PERCENTAGE_Y * SCREEN_HEIGHT + this->text->getSize().y / 2.0f + 5});

    restartBtn = new Button("restartBtn.png", 100.f, SCREEN_HEIGHT * (1.f - FIELD_PERCENTAGE_Y),
        { SCREEN_WIDTH - 100.f, FIELD_PERCENTAGE_Y * SCREEN_HEIGHT });
    restartBtn->setFillColor(sf::Color::White);
}