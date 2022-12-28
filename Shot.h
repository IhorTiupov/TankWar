#pragma once
#include "IGameItem.h"


class Shot : public IGameItem
{
public:
	Shot(std::vector<std::vector<char>>& f, int x, int y, MoveType direction);
	void shotTank();
	int getX() const;
	int getY() const;
	Shot& operator=(const Shot& item);
	bool operator==(const Shot& item);
private:
	void clear() override;
	void draw(std::vector<std::vector<char>>& field) override;
	void move(MoveType type) override;

	std::vector<std::vector<char>>& field;
	MoveType direction = MoveType::Right;
};

