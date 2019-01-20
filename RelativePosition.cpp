#include "RelativePosition.h"

std::pair<int, int> RelativePosition::calculateRelativePosition(std::pair<int, int> mainPos, std::pair<int, int> otherPos)
{

	int deltaX = otherPos.first - mainPos.first;
	int deltaY = otherPos.second - mainPos.second;

	if (deltaX == 0 && deltaY >= 0)
		return DOWN;
	if (deltaX == 0 && deltaY <= 0)
		return UP;

	double tangens = deltaY / deltaX;

	if (deltaX >= 0) {
		if (deltaY >= 0) {
			if (tangens <= 1) return RIGHT;
			if (tangens > 1) return DOWN;
		}
		if (deltaY < 0) {
			if (tangens <= -1) return UP;
			if (tangens > -1) return RIGHT;
		}
	}
	if (deltaX < 0) {
		if (deltaY >= 0) {
			if (tangens <= -1) return DOWN;
			if (tangens > -1) return LEFT;
		}
		if (deltaY < 0) {
			if (tangens <= 1) return LEFT;
			if (tangens > 1) return UP;
		}
	}
	return UP;
}
