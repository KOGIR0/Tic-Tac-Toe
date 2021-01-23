#include <map>
#include <vector>


class GameResources
{
public:


private:
    int playerNum;
    bool victory;
    int fillCellsNum;
    gameStatus status;
    std::vector<std::vector<symbol>> map;
    std::map<int, std::string> playerSign;
    std::map<int, std::string> playerName;

    sf::RenderWindow* window;
    Field* ticTacToeField;
    Button* restartBtn;
    Text* text;
    MainMenu* menu;
}