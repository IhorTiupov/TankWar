#include"Shot.h"
#include "gameconsts.h"



Shot::Shot(std::vector<std::vector<char>>& f, int x, int y) : IGameItem(x, y), field(f)
{}

void Shot::shotTank()
{
	if (true)
	{
		while (ItemX < gameconsts::width)
		{
			field[ItemY][ItemX++] = 'o';
		}
	}
	clear();
}

void Shot::clear()
{
	if (true)
	{
		while (ItemX < gameconsts::width)
		{
			field[ItemY][ItemX++] = ' ';
		}
	}
}

void Shot::move(MoveType type)
{

}

void Shot::clearShot()
{
}

void Shot::draw(std::vector<std::vector<char>>& field)
{
}

