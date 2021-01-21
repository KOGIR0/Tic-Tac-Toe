#include "Field.h"

Field::Field(const int& screenWidth, const int& screenHeight, const int& cellNum)
{
    this->cellNum = cellNum;
    setFieldSize(screenWidth, screenHeight);
    createBoolMapAndDefaultSpriteMap();
}

sf::Vector2f Field::getCellSize()
{
    return this->cellSize;
}

void Field::clear()
{
    this->createBoolMapAndDefaultSpriteMap();
}

sf::Vector2f Field::getClickedCellIndexes(const sf::Vector2i& position)
{
    for (int i = 0; i < this->cellNum; i++)
    {
        for (int j = 0; j < this->cellNum; j++)
        {
            if (field[i][j].clicked(position))
            {
                return sf::Vector2f(i, j);
            }
        }
    }
    return { -1, -1 };
}

sf::Vector2f Field::getClickedCellIndexes(const float& x, const float& y)
{
    for (int i = 0; i < this->cellNum; i++)
    {
        for (int j = 0; j < this->cellNum; j++)
        {
            if (field[i][j].clicked(sf::Vector2f( x, y )))
            {
                return sf::Vector2f(i, j);
            }
        }
    }
    return { -1, -1 };
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw tiles
    for (int i = 0; i < this->cellNum; i++)
    {
        for (int j = 0; j < this->cellNum; j++)
        {
            target.draw(field[i][j]);
        }
    }

    // draw sprites
    for (int i = 0; i < spriteMap.size(); i++)
    {
        for (int j = 0; j < spriteMap[i].size(); j++)
        {
            if (map[i][j])
            {
                target.draw(spriteMap[i][j]);
            }
        }
    }
}

void Field::setFieldSize(const float& width, const float& height)
{
    std::vector<std::vector<Button>> newfield;
    this->cellSize = sf::Vector2f(float(width) / cellNum, float(height) / cellNum);
    if (cellNum % 2 == 0)
    {
        // fill field with color like in chess
        newfield = fillEvenCellNum();
    }
    else {
        newfield = fillOddCellNum();
    }
    field = newfield;
    this->setCellSize(this->cellSize);
}

std::vector<std::vector<Button>> Field::fillEvenCellNum()
{
    sf::Color grey(80, 80, 80);
    sf::Color white(211, 211, 211);
    std::vector<Button> line(cellNum);
    std::vector<std::vector<Button>> newfield(cellNum);

    for (int i = 0; i < cellNum; i++)
    {
        for (int j = 0; j < cellNum; j++)
        {
            line[j] = Button(cellSize.x, cellSize.y, { j * cellSize.x, i * cellSize.y });
            if (i % 2 == 0)
            {
                if ((j) % 2 == 0)
                {
                    line[j].setFillColor(grey);
                }
                else {
                    line[j].setFillColor(white);
                }
            }
            else {
                if ((j) % 2 == 1)
                {
                    line[j].setFillColor(grey);
                }
                else {
                    line[j].setFillColor(white);
                }
            }
        }
        newfield[i] = line;
    }
    return newfield;
}

std::vector<std::vector<Button>> Field::fillOddCellNum()
{
    sf::Color grey(80, 80, 80);
    sf::Color white(211, 211, 211);
    std::vector<Button> line(cellNum);
    std::vector<std::vector<Button>> newfield(cellNum);

    for (int i = 0; i < cellNum; i++)
    {
        for (int j = 0; j < cellNum; j++)
        {
            line[j] = Button(cellSize.x, cellSize.y, { j * cellSize.x, i * cellSize.y });
            if ((j + i * cellNum) % 2 == 0)
            {
                line[j].setFillColor(grey);
            }
            else {
                line[j].setFillColor(white);
            }
        }
        newfield[i] = line;
    }
    return newfield;
}

void Field::createBoolMapAndDefaultSpriteMap()
{
    // bool map which shows clicked cells
    std::vector<bool> line(this->cellNum, false);
    std::vector<std::vector<bool>> newBoolMap(this->cellNum, line);
    this->map = newBoolMap;
    // bool map which shows clicked cells

    // map with sprites in cells
    std::vector<Sprite> ticTakToeLine(this->cellNum,  Sprite("X.png"));
    std::vector<std::vector<Sprite>> newSpriteMap(this->cellNum, ticTakToeLine);
    this->spriteMap = newSpriteMap;
    // map with sprites in cells
}

void Field::adjustCellToCellSize(const int& i, const int& j)
{
    spriteMap[i][j].setSize(cellSize);
    float x = cellSize.x * j;
    float y = cellSize.y * i;
    sf::Vector2f spritePosition(x, y);
    spriteMap[i][j].setPosition(spritePosition);
}

void Field::markCell(const int& i, const int& j, const std::string& texturePath)
{
    if (!map[i][j])
    {
        map[i][j] = true;
        spriteMap[i][j].setTexture(texturePath);
        adjustCellToCellSize(i, j);
    }
}

bool Field::cellWasClicked(sf::Vector2f position)
{
    return map[position.x][position.y];
}

void Field::setCellSize(sf::Vector2f cellSize)
{
    this->cellSize = cellSize;
    for (int i = 0; i < spriteMap.size(); i++)
    {
        for (int j = 0; j < spriteMap[i].size(); j++)
        {
            adjustCellToCellSize(i, j);
        }
    }
}

std::vector<std::vector<bool>> Field::getBoolMap()
{
    return map;
}