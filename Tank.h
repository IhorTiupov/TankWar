#pragma once
#include "gameconsts.h"

using namespace gameconsts;

class Tank
{
public:
	Tank();
	void draw(std::vector<std::vector<char>>& field);
	/*void setTankX(int x);
	void setTankY(int y);*/
	void moveTankLeft();
	void moveTankRight();
	void moveTankUp();
	void moveTankDown();
	void turnGunLeft();
	void turnGunRight();
	void turnGunUp();
	void turnGunDown();
private:
	int tankX;
	int tankY;
	int gunX;
	int gunY;
	void turnGun(const char position);
};

