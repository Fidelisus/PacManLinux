#include "BlueGhost.h"


BlueGhost::BlueGhost(QString path, QGraphicsItem * parent) : Ghost(path)
{
}

void BlueGhost::planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection)
{
	if (spawnWalker) {
		leaveSpawn(RIGHT);
	}
	else {
		if (escape) {
			isSlower = true;
		}
		else {
			isSlower = false;
		}

		goToDirection(std::pair<int, int>(-pacmanPosition.first, -pacmanPosition.second));
	}
}