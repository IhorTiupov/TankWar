#pragma once
#include<vector>
#include "MoveType.h"

class IGameItem
{
public:
	IGameItem(int x, int y) : ItemX(x), ItemY(y)
	{}
	virtual void draw(std::vector<std::vector<char>>& field) = 0;
	virtual void move(MoveType type) = 0;
protected:
	virtual void clear() = 0;
	//virtual void shotTank() = 0;
protected:
	int ItemX;
	int ItemY;
};
