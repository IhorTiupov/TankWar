#include "Tank.h"

Tank::Tank() : IGameItem(width / 2, height / 2)
             , gunX(widthDimensionsTank + coordX)
             , gunY(heightDimensionsTank - 2 + coordY)
{}
void Tank::draw(std::vector<std::vector<char>>& field)
{
    field[gunY][gunX] = 'H';

    for (size_t i = coordY; i < coordY+heightDimensionsTank; i++)
    {
        for (size_t j = coordX; j < coordX+widthDimensionsTank; j++)
        {
            field[i][j] = 'X';
        }
    }
}
void Tank::clear()
{
    field[gunY][gunX] = ' ';

    for (size_t i = coordY; i < coordY + heightDimensionsTank; i++)
    {
        for (size_t j = coordX; j < coordX + widthDimensionsTank; j++)
        {
            field[i][j] = ' ';
        }
    }
}
void Tank::moveTankLeft()
{

    if (coordX > 1)
    {
        clear();
        coordX--;
    }
    gunX = coordX -1;
    gunY = coordY + 1;
}
void Tank::moveTankRight()
{
    if (coordX < width - widthDimensionsTank-1)
    {
        clear();
        coordX++;
    }
    gunX = coordX + 3;
    gunY = coordY + 1;
}
void Tank::moveTankUp()
{
    if (coordY > 1)
    {
        clear();
        coordY--;
    }
    gunX = coordX + 1;
    gunY = coordY - 1;
}
void Tank::moveTankDown()
{
    if(coordY < height - widthDimensionsTank - 1)
    {
        clear();
        coordY++;
    }
    gunX = coordX + 1;
    gunY = coordY + 3;
}

void Tank::move(MoveType type)
{
    clear();
    switch (type)
    {
    case MoveType::Left :
        moveTankLeft();
        break;
    case MoveType::Right:
        moveTankRight();
        break;
    case MoveType::Up:
        moveTankUp();
        break;
    case MoveType::Down:
        moveTankDown();
        break;
    }
}
