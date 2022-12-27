#pragma once
#include <vector>

namespace gameconsts
{
	const int heightDimensionsTank = 3;
	const int widthDimensionsTank = 3;
	const int height = 25;
	const int width = 70;
	static std::vector<std::vector<char>> field(height, std::vector<char>(width));
}
