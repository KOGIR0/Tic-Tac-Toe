#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Field.h"
#include "Sprite.h"
#include "TicTakToe.h"
#include "Text.h"

/*void updateWindow(sf::RenderWindow& window, TicTakToe& game)
{
    window.clear();
    game.ticTacToeField.draw(window);
    game.text.draw(window);
    game.restartBtn.draw(window);
    window.display();
}

void processLeftBtnClick(const sf::Vector2i& mousePos, TicTakToe& game)
{
    sf::Vector2f cellPosition = game.ticTacToeField.getClickedCellIndexes(mousePos);
    if (game.restartBtn.clicked(mousePos))
    {
        game.text.setString("Cross turn");
        //game = TicTakToe();
        game.ticTacToeField.clear();
    }
    if (cellPosition.x != -1 && !game.getVictory())
    {
        if (!game.ticTacToeField.cellWasClicked(cellPosition))
        {
            game.text.setString(game.playerName[game.getNextPlayerNum()] + " turn");
            game.setSymbol(cellPosition, game.playerSign[game.getPlayerNum()]);
        }
        game.ticTacToeField.markCell(cellPosition.x, cellPosition.y, game.playerSign[game.getPlayerNum()] + ".png");
        if (game.checkWinCondition(cellPosition, game.ticTacToeField.getBoolMap()))
        {
            game.setVictory(true);
            game.text.setString(game.playerName[game.getPlayerNum()] + " Won!");
        }
        game.nextPlayer();
    }
}*/

int main() {
    //TicTakToe game;
	//sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TIC TAK TOE");
    //sf::Image icon;
    //icon.loadFromFile("X.png");
    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    TicTakToe game;
    //Field ticTakToeField(FIELD_PERCENTAGE_X * SCREEN_WIDTH, FIELD_PERCENTAGE_Y * SCREEN_HEIGHT, CELL_NUMBER);

    while (game.isRunning())
    {
        /*sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = { event.mouseButton.x, event.mouseButton.y };
                    processLeftBtnClick(mousePos, game);
                }
                break;
            case sf::Event::Resized:
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                sf::Vector2u newSize = window.getSize();
                game.ticTacToeField.setFieldSize(FIELD_PERCENTAGE_X * newSize.x, FIELD_PERCENTAGE_Y * newSize.y);

                game.text.setPosition({ 0, FIELD_PERCENTAGE_Y * newSize.y });
                game.restartBtn = Button(100.f, newSize.y * (1.f - FIELD_PERCENTAGE_Y),
                    { newSize.x - 100.f, FIELD_PERCENTAGE_Y * newSize.y });
                game.restartBtn.setFillColor(sf::Color::Blue);
                break;
            }
        }*/
        //updateWindow(window, game);
        game.process();
        game.updateWindow();
    }
	return 0;
}