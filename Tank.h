#pragma once
#include "gameconsts.h"
#include "MoveType.h"

using namespace gameconsts;

class Tank
{
public:
	Tank();
	void draw(std::vector<std::vector<char>>& field);
	void move(MoveType type);

private:
	int tankX;
	int tankY;
	int gunX;
	int gunY;

private:
	void turnGun(const char position);
	void moveTankLeft();
	void moveTankRight();
	void moveTankUp();
	void moveTankDown();

	//utility function
	void clear();

};

