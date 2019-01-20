#pragma once
#include "Ghost.h"
class YellowGhost :
	public Ghost
{
public:
	YellowGhost(QString path, QGraphicsItem * parent = nullptr);

	virtual void planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection) override;
};

