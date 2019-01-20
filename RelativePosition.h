#pragma once
#include <utility>

#define UP std::pair<int, int>(0, -1)
#define DOWN std::pair<int, int>(0, 1)
#define RIGHT std::pair<int, int>(1, 0)
#define LEFT std::pair<int, int>(-1, 0)

class RelativePosition
{
public:
	static std::pair<int, int> calculateRelativePosition(std::pair<int, int> mainPos, std::pair<int, int> otherPos);
};

