#pragma once

#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QObject>
#include <string>
#include <vector>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <stdlib.h>
#include <time.h> 

#include <Constants.h>
#include <GraphicBarrierItem.h>
#include <SmallDot.h>
#include <BigDot.h>
#include "Counter.h"
#include "PacMan.h"
#include "GraphicSpawnItem.h"

#include "Ghost.h"
#include "BlueGhost.h"
#include "RedGhost.h"
#include "YellowGhost.h"
#include "PinkGhost.h"

class Board : public QGraphicsView
{
	Q_OBJECT

public:
	Board();
	std::vector<MyGraphicsRectItem*> walls;
	std::vector<MyGraphicsRectItem*> spawnArea;

private:
	std::vector<std::string> map;
	QTimer * gameTimer;
	QTimer * ghostTimer;
	QGraphicsScene *scene;
	Counter * counter;

	std::list<Moveable*> creatures;
	std::list<GraphicDotItem*> dots;
	PacMan * pacman;

	bool eating;
	int eatingTimeCounter = 0;
	bool gameEnd;

	void prepareScene();
	void prepareTimer();
	void prepareCounter();
	void loadMap();

	void restartGame();
	void startNewGame();
	void addObjects();
	void addSpawnItem(unsigned int row, unsigned int column);
	void clearBoard();
	void setVariables();

	void checkWinConditions();
	void defeat();
	void checkEating();
	void checkGhostCollisions();

	void keyPressEvent(QKeyEvent *event);
	void checkDotCollision();
	Moveable * addCreature(Moveable* creature, unsigned int row, unsigned int column);
	void bigDotCollected();


public slots:
	void moveAll();
	void ghostThink();
};
