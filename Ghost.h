#pragma once
#include "Moveable.h"
#include "RelativePosition.h"

class Ghost :
	public Moveable
{
public:
	Ghost(QString path, QGraphicsItem * parent = nullptr);

	virtual void planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection) = 0;
	void respawn();
	void setEscape(bool value);
protected:
	bool escape;
	int slowDown;

	void leaveSpawn(std::pair<int, int> startingDirection);
	void goToDirection(std::pair<int, int> direction);

	std::vector<std::pair<int, int>> checkSurroundings();
};

