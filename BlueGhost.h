#pragma once
#include "Ghost.h"
class BlueGhost :
	public Ghost
{
public:
	BlueGhost(QString path, QGraphicsItem * parent = nullptr);

	virtual void planNext(std::pair<int, int> pacmanPosition, std::pair<int, int> pacmanDirection) override;
};

