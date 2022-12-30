#include "Walls.h"
#include "gameconsts.h"

Walls::Walls(std::vector<std::vector<char>>& f, int x, int y) : IGameItem(x, y), field(f)
{}

void Walls::draw(std::vector<std::vector<char>>& field)
{
    for (size_t i = 0; i < gameconsts::height; i++)
    {
        for (size_t j = 0; j < gameconsts::width-1; j++)
        {
            field[i][1] = 'p';
            field[1][j] = 'r';
            field[gameconsts::height - 1][j] = 'm';
            field[i][gameconsts::width-1] = 'c';
        }
    }
}

void Walls::clear()
{}

void Walls::move(MoveType type)
{}
