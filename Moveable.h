#pragma once
#include <QGraphicsPixmapItem>
#include <string>
#include <map>

#include "GraphicBarrierItem.h"
#include "GraphicSpawnItem.h"
#include "MyGraphicsRectItem.h"
#include <Constants.h>

class Moveable : public QGraphicsPixmapItem
{
public:
	void moveMoveable(const std::vector<MyGraphicsRectItem*> & walls, const std::vector<MyGraphicsRectItem*> & spawn);
	void setNext(std::pair<int, int> pair);
	void setImage(QString path);
	
	std::pair<int, int> currentDirection;
protected:
	bool spawnWalker = false;
	QString baseImage = "";
	std::pair<int, int> plannedDirection;
	std::map<QString, QPixmap> images;
	bool stopped = false;
	int stoppedCounter = 0;
	bool setRotate = false;
	bool firstSet = true;
	int slowDown = 0;
	bool isSlower = false;

	bool slowDownMoves();

	bool canMove(const QString mode, std::pair<int, int> pair);

	void makeRotation(std::pair<int, int> direction);
	void rotate(int angle);
	void loadImage(QString path);
	void stopTimer();

};

