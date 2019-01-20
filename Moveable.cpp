#include "Moveable.h"

void Moveable::moveMoveable(const std::vector<MyGraphicsRectItem*> & walls, const std::vector<MyGraphicsRectItem*> & spawn)
{
	if (!isSlower || slowDownMoves()) {
		if (!stopped && canMove(MODES_WALLS, plannedDirection) && (canMove(MODES_SPAWN, plannedDirection) || spawnWalker)) {
			moveBy(plannedDirection.first, plannedDirection.second);
			currentDirection = plannedDirection;
			if (setRotate) {
				makeRotation(currentDirection);
			}
			// moving throught walls
			if (x() >= BOARD_X - CREATURES_CELL) {
				setX(0);
			}
			else if (x() <= 0) {
				setX(BOARD_X - CREATURES_CELL);
			}
		}
		else if (!stopped && canMove(MODES_WALLS, currentDirection) && (canMove(MODES_SPAWN, currentDirection) || spawnWalker)) {
			moveBy(currentDirection.first, currentDirection.second);
			// moving throught walls
			if (x() > BOARD_X - CREATURES_CELL) {
				setX(0);
			}
			else if (x() <= 0) {
				setX(BOARD_X - CREATURES_CELL);
			}
		}

		if (stopped) {
			stopTimer();
		}
	}
}

void Moveable::stopTimer()
{
	stoppedCounter++;
	if (stoppedCounter >= RESPAWN_TIME) {
		stopped = false;
		stoppedCounter = 0;
	}
}

void Moveable::setNext(std::pair<int, int> pair)
{
	plannedDirection = pair;
}

bool Moveable::slowDownMoves()
{
	if (slowDown >= SLOW_DOWN) {
		slowDown = 0;
		return true;
	}
	else {
		slowDown++;
		return false;
	}
}

bool Moveable::canMove(const QString mode, std::pair<int, int> pair)
{
	moveBy(pair.first, pair.second);

	QList<QGraphicsItem *> colliding = this->collidingItems(Qt::IntersectsItemBoundingRect);

	moveBy(-pair.first, -pair.second);

	for (int i = 0, n = colliding.size(); i < n; i++) {
		if (dynamic_cast<GraphicBarrierItem*>(colliding[i]) && (mode == MODES_WALLS || mode == MODES_BOTH)) {
			return false;
		}
		if (dynamic_cast<GraphicSpawnItem*>(colliding[i]) && (mode == MODES_SPAWN || mode == MODES_BOTH)) {
			return false;
		}
	}
	return true;
}

void Moveable::makeRotation(std::pair<int, int> direction)
{
	if (direction == LEFT) {
		rotate(ROTATION_LEFT);;
	}
	else if (direction == RIGHT) {
		rotate(ROTATION_RIGHT);
	}
	else if (direction == UP) {
		rotate(ROTATION_UP);
	}
	else if (direction == DOWN) {
		rotate(ROTATION_DOWN);
	}
}

void Moveable::rotate(int angle)
{
	this->setTransformOriginPoint(this->boundingRect().center());
	this->setRotation(angle);
}

void Moveable::loadImage(QString path)
{
	try {
		QPixmap bgPixmap(QString(CUR_DIR).append(path));
		QPixmap scaled = bgPixmap.scaled(QSize(CREATURES_CELL, CREATURES_CELL));
		images.emplace(path, scaled);
		setPixmap(scaled);
	}
	catch (...) {
		abort();
	}
}

void Moveable::setImage(QString path)
{
	if (firstSet) {
		baseImage = path;
		firstSet = false;
	}

	if(path == DEFAULT)
		setPixmap(images[baseImage]);
	else
		setPixmap(images[path]);
}


