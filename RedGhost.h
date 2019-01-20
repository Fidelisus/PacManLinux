#pragma once
#include "Ghost.h"


class RedGhost :
	public Ghost
{
public:
	RedGhost(QString path, QGraphicsItem * parent = nullptr);

	virtual void planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection) override;
};

