#pragma once
#include "IGameItem.h"

class Walls : public IGameItem
{
public:
	Walls(std::vector<std::vector<char>>& f, int x, int y);
	void draw(std::vector<std::vector<char>>& field) override;
private:
	std::vector<std::vector<char>>& field;
private:
	void clear() override;
	void move(MoveType type) override;
};

