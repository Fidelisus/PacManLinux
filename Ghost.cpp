#include "Ghost.h"
#include "GraphicSpawnItem.h"
#include <stdlib.h>
#include <time.h> 

Ghost::Ghost(QString path, QGraphicsItem * parent)
{
	loadImage(path);
	loadImage(GREY_IMG_FILE);
	setImage(path);
	currentDirection = RIGHT;
	plannedDirection = RIGHT;
	stopped = true;
	spawnWalker = true;
	escape = false;
	slowDown = 0;
}

void Ghost::leaveSpawn(std::pair<int, int> startingDirection)
{
	currentDirection = startingDirection;
	plannedDirection = UP;

	QList<QGraphicsItem *> colliding = this->collidingItems();

	for (int i = 0, n = colliding.size(); i < n; i++) {
		if (dynamic_cast<GraphicSpawnItem*>(colliding[i])) {
			return;
		}
	}

	spawnWalker = false;
}

void Ghost::respawn()
{
	setPos(RESPAWN);
	stopped = true;
	spawnWalker = true;
}

void Ghost::setEscape(bool value)
{
	escape = value;
}

std::vector<std::pair<int, int>> Ghost::checkSurroundings()
{
	std::vector<std::pair<int, int>> directions;

	if (x() < CELL_LENGTH) {
		directions.emplace_back(LEFT);
		return directions;
	}
	if (x() > BOARD_X - CELL_LENGTH) {
		directions.emplace_back(RIGHT);
		return directions;
	}

	if (canMove("both", UP)) directions.emplace_back(UP);
	if (canMove("both", DOWN)) directions.emplace_back(DOWN);
	if (canMove("both", LEFT)) directions.emplace_back(LEFT);
	if (canMove("both", RIGHT)) directions.emplace_back(RIGHT);

	return directions;
}

void Ghost::goToDirection(std::pair<int, int> direction)
{
	std::vector<std::pair<int, int>> surroundings;
	surroundings = this->checkSurroundings();
	std::pair<int, int> nextDirection;
	std::pair<int, int> relativePos = RelativePosition::calculateRelativePosition(std::pair<int, int>(x(), y()), direction);

	for (int i = 0; i < surroundings.size(); i++) {
		if (surroundings[i] == relativePos) {
			plannedDirection = relativePos;
			return;
		}
	}

	for (int i = 0; i < surroundings.size(); i++) {
		if (surroundings[i] == LEFT && relativePos != RIGHT && currentDirection != RIGHT) {
			plannedDirection = LEFT;
			return;
		}
		if (surroundings[i] == RIGHT && relativePos != LEFT && currentDirection != LEFT) {
			plannedDirection = RIGHT;
			return;
		}
		if (surroundings[i] == UP && relativePos != DOWN && currentDirection != DOWN) {
			plannedDirection = UP;
			return;
		}
		if (surroundings[i] == DOWN && relativePos != UP && currentDirection != UP) {
			plannedDirection = DOWN;
			return;
		}
	}

	plannedDirection = surroundings[rand() % (surroundings.size())];
}