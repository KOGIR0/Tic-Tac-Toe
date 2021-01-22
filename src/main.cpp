#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Field.h"
#include "Sprite.h"
#include "TicTacToe.h"
#include "Text.h"

int main() {
    TicTacToe game;

    while (game.isRunning())
    {
        game.process();
        game.updateWindow();
    }
	return 0;
}