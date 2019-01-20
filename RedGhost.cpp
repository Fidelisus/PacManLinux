#include "RedGhost.h"
#include <QDebug>

RedGhost::RedGhost(QString path, QGraphicsItem * parent) : Ghost(path)
{
}

void RedGhost::planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection)
{
	if (spawnWalker) {
		leaveSpawn(RIGHT);
	}
	else {
		if (escape) {
			isSlower = true;
			goToDirection(std::pair<int, int>(-pacmanPosition.first, - pacmanPosition.second));
		}
		else {
			isSlower = false;
			goToDirection(pacmanPosition);
		}
	}
}
