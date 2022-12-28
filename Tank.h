#pragma once
#include "gameconsts.h"
#include "MoveType.h"
#include "IGameItem.h"
using namespace gameconsts;

class Tank : public IGameItem
{
public:
	Tank(std::vector<std::vector<char>>& f);
	void draw(std::vector<std::vector<char>>& field);
	void move(MoveType type);
	int getGunX();
	int getGunY();

private:
	int gunX;
	int gunY;
	std::vector<std::vector<char>>& field;

private:
	void turnGun(const char position);
	void moveTankLeft();
	void moveTankRight();
	void moveTankUp();
	void moveTankDown();


	//utility function
	void clear();

};

