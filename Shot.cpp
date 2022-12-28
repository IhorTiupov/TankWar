#include"Shot.h"
#include "gameconsts.h"



Shot::Shot(std::vector<std::vector<char>>& f, int x, int y, MoveType direction_)
							  : IGameItem(x, y), field(f), direction(direction_)
{}

void Shot::shotTank()
{
	switch (direction)
	{
	case MoveType::Left:
		clear();
		if (ItemX > 1)
		{
			field[ItemY][--ItemX] = 'o';
		}
		break;
	case MoveType::Right:
		clear();
			if (ItemX < gameconsts::width-1)
			{
				field[ItemY][++ItemX] = 'o';
			}
		break;
	case MoveType::Up:
		clear();
	if (ItemY > 1)
	{
		field[--ItemY][ItemX] = 'o';
	}
		break;
	case MoveType::Down:
	clear();
	if (ItemY < gameconsts::height - 1)
	{
		field[++ItemY][ItemX] = 'o';
	}
		break;
	}
}

int Shot::getX() const
{
	return ItemX;
}

int Shot::getY() const
{
	return ItemY;
}

Shot& Shot::operator=(const Shot& item)
{
	if (this == &item) {
		return *this;
	}
	ItemX = item.ItemX;
	ItemY = item.ItemY;
	direction = item.direction;
	field = item.field;
	return *this;
}

bool Shot::operator==(const Shot& item)
{
	return ItemX == item.ItemX && ItemY == item.ItemY && direction == item.direction;
}

void Shot::clear()
{
	field[ItemY][ItemX] = ' ';
}

void Shot::move(MoveType type)
{}
void Shot::draw(std::vector<std::vector<char>>& field)
{}

