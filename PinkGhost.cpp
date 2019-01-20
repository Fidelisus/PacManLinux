#include "PinkGhost.h"

PinkGhost::PinkGhost(QString path, QGraphicsItem * parent) : Ghost(path)
{
}

void PinkGhost::planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection)
{
	if (spawnWalker) {
		leaveSpawn(LEFT);
	}
	else {
		if (escape) {
			isSlower = true;
			goToDirection(std::pair<int, int>(-pacmanPosition.first, -pacmanPosition.second));
		}
		else {
			isSlower = false;
			goToDirection(std::pair<int, int>(pacmanPosition.first + pacmanDirection.first * PINK_STRATEGY_OFFSET,
						  pacmanPosition.second + pacmanDirection.second * PINK_STRATEGY_OFFSET));
		}
	}
}
