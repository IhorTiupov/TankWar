#pragma once
#include "Tank.h"

class GameControl
{
public:
	GameControl(Tank& t, bool& stopGame);
	void moveControl();
private:
	Tank tank;
	bool stop;
};
