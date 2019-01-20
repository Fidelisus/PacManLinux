#pragma once
#include "Ghost.h"
class PinkGhost :
	public Ghost
{
public:
	PinkGhost(QString path, QGraphicsItem * parent = nullptr);

	virtual void planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection) override;
};

