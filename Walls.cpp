#include "Walls.h"
#include "gameconsts.h"

Walls::Walls(std::vector<std::vector<char>>& f, int x, int y) : IGameItem(x, y), field(f)
{}

void Walls::draw(std::vector<std::vector<char>>& field)
{
    for (size_t i = 0; i < gameconsts::height; i++)
    {
        for (size_t j = 0; j < gameconsts::width; j++)
        {
            field[i][0] = '*';
            field[0][j] = '*';
            field[gameconsts::height - 1][j] = '*';
            field[i][gameconsts::width - 1] = '*';
        }
    }
}

void Walls::clear()
{}

void Walls::move(MoveType type)
{}
