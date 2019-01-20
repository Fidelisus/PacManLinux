#include "PacMan.h"


PacMan::PacMan(QGraphicsItem * parent)
{
	loadImage(PACMAN_IMG_FILE);
	setImage(PACMAN_IMG_FILE);
	currentDirection = RIGHT;
	plannedDirection = RIGHT;
	stopped = true;
	setRotate = true;
}
