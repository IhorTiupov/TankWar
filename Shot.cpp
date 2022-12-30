#include"Shot.h"
#include "gameconsts.h"
#include <iostream>


Shot::Shot(std::vector<std::vector<char>>& f, int x, int y, MoveType direction_)
							  : IGameItem(x, y), field(f), direction(direction_)
{}

void Shot::shotTank()
{
	clear();
	switch (direction)
	{
	case MoveType::Left:		
		if (ItemX > 1)
		{
			if (field[ItemY][ItemX - 1]=='*')
			{
				gameconsts::scorce++;
				std::cout << "score = " << gameconsts::scorce << std::endl;
			}	
			field[ItemY][--ItemX] = 'o';
		}
		break;
	case MoveType::Right:
		if (ItemX < gameconsts::width-1)
		{
			/*if (field[ItemY][ItemX + 1] == '*')
			{
				gameconsts::scorce++;
				std::cout << "score = " << gameconsts::scorce << std::endl;
			}*/
			field[ItemY][++ItemX] = 'o';
		}
		break;
	case MoveType::Up:
		if (ItemY > 1)
		{
			field[--ItemY][ItemX] = 'o';
		}
		break;
	case MoveType::Down:
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

