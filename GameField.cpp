#include "GameField.h"
#include <iostream>

void GameField::printField()
{
    for (size_t i = 0; i < gameconsts::height; i++)
    {
        for (size_t j = 0; j < gameconsts::width; j++)
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

void GameField::fullingField(char ch)
{
    for (size_t i = 0; i < gameconsts::height; i++)
    {
        for (size_t j = 0; j < gameconsts::width; j++)
        {
            field[i][j] = ch;
        }
    }
}

std::vector<std::vector<char>>& GameField::getField()
{
    return field;
}
