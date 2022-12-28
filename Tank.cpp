#include "Tank.h"


Tank::Tank(std::vector<std::vector<char>>&f) : IGameItem(width / 2, height / 2)
                                             , gunX(widthDimensionsTank + ItemX)
                                             , gunY(heightDimensionsTank - 2 + ItemY)
                                             , field(f)
{
}
void Tank::draw(std::vector<std::vector<char>>& field)
{
    field[gunY][gunX] = 'H';

    for (size_t i = ItemY; i < ItemY+heightDimensionsTank; i++)
    {
        for (size_t j = ItemX; j < ItemX+widthDimensionsTank; j++)
        {
            field[i][j] = 'X';
        }
    }
}
void Tank::clear()
{
    field[gunY][gunX] = ' ';

    for (size_t i = ItemY; i < ItemY + heightDimensionsTank; i++)
    {
        for (size_t j = ItemX; j < ItemX + widthDimensionsTank; j++)
        {
            field[i][j] = ' ';
        }
    }
}
void Tank::moveTankLeft()
{
    if (ItemX > 1)
    {
        clear();
        ItemX--;
    }
    gunX = ItemX -1;
    gunY = ItemY + 1;
}
void Tank::moveTankRight()
{
    if (ItemX < width - widthDimensionsTank-1)
    {
        clear();
        ItemX++;
    }
    gunX = ItemX + 3;
    gunY = ItemY + 1;
}
void Tank::moveTankUp()
{
    if (ItemY > 2)
    {
        clear();
        ItemY--;
    }
    gunX = ItemX + 1;
    gunY = ItemY - 1;
}
void Tank::moveTankDown()
{
    if(ItemY < height - widthDimensionsTank - 1)
    {
        clear();
        ItemY++;
    }
    gunX = ItemX + 1;
    gunY = ItemY + 3;
}

void Tank::move(MoveType type)
{
    switch (type)
    {
    case MoveType::Left :
        direction = MoveType::Left;
        moveTankLeft();
        break;
    case MoveType::Right:
        direction = MoveType::Right;
        moveTankRight();
        break;
    case MoveType::Up:
        direction = MoveType::Up;
        moveTankUp();
        break;
    case MoveType::Down:
        direction = MoveType::Down;
        moveTankDown();
        break;
    }
}

int Tank::getGunX()
{
    return gunX;
}

int Tank::getGunY()
{
    return gunY;
}

MoveType Tank::getDirection()
{
    return direction;
}
