#include "YellowGhost.h"
#include <stdlib.h>
#include <time.h> 

YellowGhost::YellowGhost(QString path, QGraphicsItem * parent) : Ghost(path)
{
}

void YellowGhost::planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection)
{
	if (spawnWalker) {
		leaveSpawn(LEFT);
	}
	else {
		std::vector<std::pair<int, int>> surroundings;
		surroundings = this->checkSurroundings();

		std::pair<int, int> nextDirection = surroundings[rand() % (surroundings.size())];

		if (nextDirection == RIGHT && currentDirection != LEFT) plannedDirection = nextDirection;
		if (nextDirection == UP && currentDirection != DOWN) plannedDirection = nextDirection;
		if (nextDirection == DOWN && currentDirection != UP) plannedDirection = nextDirection;
		if (nextDirection == LEFT && currentDirection != RIGHT) plannedDirection = nextDirection;
	}
}

