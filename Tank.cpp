#include "Tank.h"

Tank::Tank() : tankX(width / 2)
             , tankY(height / 2)
             , gunX(widthDimensionsTank + tankX)
             , gunY(heightDimensionsTank - 2 + tankY)
{}

void Tank::draw(std::vector<std::vector<char>>& field)
{
    field[gunY][gunX] = 'H';

    for (size_t i = tankY; i < tankY+heightDimensionsTank; i++)
    {
        for (size_t j = tankX; j < tankX+widthDimensionsTank; j++)
        {
            field[i][j] = 'X';
        }
    }
}
void Tank::clear()
{
    field[gunY][gunX] = ' ';

    for (size_t i = tankY; i < tankY + heightDimensionsTank; i++)
    {
        for (size_t j = tankX; j < tankX + widthDimensionsTank; j++)
        {
            field[i][j] = ' ';
        }
    }
}
//void Tank::setTankX(int x)
//{
//    tankX = x;
//}
//void Tank::setTankY(int y)
//{
//    tankY = y;
//}


void Tank::moveTankLeft()
{

    if (tankX > 1)
    {
        clear();
        tankX--;
    }
    gunX = tankX -1;
    gunY = tankY + 1;
}
void Tank::moveTankRight()
{
    if (tankX < width - widthDimensionsTank-1)
    {
        clear();
        tankX++;
    }
    gunX = tankX + 3;
    gunY = tankY + 1;
}
void Tank::moveTankUp()
{
    if (tankY > 1)
    {
        clear();
        tankY--;
    }
    gunX = tankX + 1;
    gunY = tankY - 1;
}
void Tank::moveTankDown()
{
    if(tankY < height - widthDimensionsTank - 1)
    {
        clear();
        tankY++;
    }
    gunX = tankX + 1;
    gunY = tankY + 3;
}

//void move(moveType)
//{
//    clear();
//    if (moveType == Left)
//    {
//        moveTankLeft();
//    }
//
//}

