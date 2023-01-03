#pragma once

#include <vector>
#include "gameconsts.h"
class GameField
{
private:
	std::vector<std::vector<char>> field{ gameconsts::height, std::vector<char>(gameconsts::width, ' ')};
public:
	void printField();
	void fullingField(char ch);
	std::vector<std::vector<char>>& getField();
};

