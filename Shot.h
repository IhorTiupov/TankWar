#pragma once
#include "IGameItem.h"


class Shot : public IGameItem
{
public:
	Shot(std::vector<std::vector<char>>& f, int x, int y);
	void shotTank();

private:
	void clearShot();
	void clear() override;
	void draw(std::vector<std::vector<char>>& field) override;
	void move(MoveType type) override;
	std::vector<std::vector<char>>& field;
};

