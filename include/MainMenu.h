#ifndef MENU
#define MENU

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Text.h"

class MainMenu : public sf::Drawable
{
public:
    MainMenu(const sf::Vector2f& screenSize);
    ~MainMenu();
    void resizeMenu(const sf::Vector2f& screenSize);
    int processClick(const sf::Vector2i& position);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Vector2f screenSize;
    Button* offlineBtn;
    Button* onlineBtn;
    Text* offlineTxt;
    Text* onlineTxt;
};

#endif