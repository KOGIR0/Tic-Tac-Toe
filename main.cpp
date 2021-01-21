#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Field.h"
#include "Sprite.h"
#include "TicTakToe.h"
#include "Text.h"

int main() {
    TicTakToe game;

    while (game.isRunning())
    {
        game.process();
        game.updateWindow();
    }
	return 0;
}