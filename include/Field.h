/*
Class creates square field background
*/

#ifndef FIELD
#define FIELD

#include <vector>
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Button.h"

class Field : public sf::Drawable
{
public:
    Field(const int& screenWidth = 500.f, const int& screenHeight = 500.f, const int& cellNum = 3);

    sf::Vector2i getClickedCellIndexes(const float& x, const float& y);
    sf::Vector2i getClickedCellIndexes(const sf::Vector2i& position);
    sf::Vector2f getCellSize();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setFieldSize(const float& width, const float& height);
    void markCell(const int& i, const int& j, const std::string& texturePath);
    bool cellWasClicked(sf::Vector2i position);
    std::vector<std::vector<bool>> getBoolMap();
    void clear();
    int getFilledCellsNum() { return this->filledCellsNum; }
    int getSize() { return this->fieldSize; }

private:
    std::vector<std::vector<Button>> fillEvenCellNum();
    std::vector<std::vector<Button>> fillOddCellNum();
    void adjustCellToCellSize(const int& i, const int& j);
    void createBoolMapAndDefaultSpriteMap();
    void setCellSize(sf::Vector2f cellSize);

    std::vector<std::vector<Button>> field;
    int cellNum;
    int filledCellsNum;
    int fieldSize;
    sf::Vector2f cellSize;
    std::vector<std::vector<bool>> map;                                           // matrix that shows what cells were pressed
    std::vector<std::vector<Sprite>> spriteMap;
};

#endif