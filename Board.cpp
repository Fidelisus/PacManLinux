#include "Board.h"

#include <fstream>
#include <iostream>
#include <QGraphicsRectItem>

Board::Board()
{
	prepareScene();
	loadMap();
	startNewGame();
}

void Board::prepareScene()
{
	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, BOARD_X, BOARD_Y);
	this->setScene(scene);
	scene->setBackgroundBrush(QBrush(Qt::lightGray));
	
	this->setFixedSize(BOARD_X, BOARD_Y);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	srand(time(NULL));

	this->show();
}

void Board::loadMap()
{
	try {
		std::ifstream file(std::string(CUR_DIR).append("map.txt"));
		for (std::string n; file >> n;)
			map.push_back(n);
		file.close();
	}
	catch (...) {
		abort();
	}
}

void Board::startNewGame()
{
	addObjects();
	prepareTimer();
	prepareCounter();
	setVariables();
}

void Board::restartGame()
{
	delete counter;
	delete gameTimer;
	startNewGame();
}

void Board::prepareTimer()
{
	gameTimer = new QTimer(this);
	connect(gameTimer, SIGNAL(timeout()), this, SLOT(moveAll()));
	connect(gameTimer, SIGNAL(timeout()), this, SLOT(ghostThink()));
	gameTimer->start(FPS);
}

void Board::prepareCounter()
{
	counter = new Counter();
	counter->setPos(COUNTER_X_POSITION, COUNTER_Y_POSITION);
	counter->setZValue(1);
	scene->addItem(counter);
}

void Board::setVariables()
{
	gameEnd = false;
	eatingTimeCounter = 0;
	eating = false;
}

void Board::addObjects()
{
	clearBoard();

	GraphicBarrierItem * wall;
	SmallDot * smallDot;
	BigDot * bigDot;

	for (unsigned int column = 0; column < map.at(0).size(); ++column) {
		for (unsigned int row = 0; row < map.size(); ++row) {
			switch (map[row][column]) {
			case '0':
				wall = new GraphicBarrierItem(NORMAL_CELL);
				scene->addItem(wall);
				walls.emplace_back(wall);
				break;
			case '1':
				smallDot = new SmallDot(SMALL_DOT_CELL);
				scene->addItem(smallDot);
				dots.emplace_back(smallDot);
				break;
			case '2':
				bigDot = new BigDot(BIG_DOT_CELL);
				scene->addItem(bigDot);
				dots.emplace_back(bigDot);
				break;
			case '3':
				addSpawnItem(row, column);
				break;
			case 'a':
				addSpawnItem(row, column);
				addCreature(new RedGhost(RED_IMG_FILE), row, column);
				break;
			case 'b':
				addSpawnItem(row, column);
				addCreature(new BlueGhost(BLUE_IMG_FILE), row, column);
				break;
			case 'c':
				addSpawnItem(row, column);
				addCreature(new YellowGhost(YELLOW_IMG_FILE), row, column);
				break;
			case 'd':
				addSpawnItem(row, column);
				addCreature(new PinkGhost(PINK_IMG_FILE), row, column);
				break;
			case 'p':
				pacman = new PacMan();
				addCreature(pacman, row, column);
				break;
			default:
				break;
			}
		}
	}
}

void Board::addSpawnItem(unsigned int row, unsigned int column)
{
	GraphicSpawnItem * spawn;
	spawn = new GraphicSpawnItem(NORMAL_CELL);
	scene->addItem(spawn);
	spawnArea.emplace_back(spawn);
}

Moveable * Board::addCreature(Moveable* creature, unsigned int row, unsigned int column)
{
	creatures.emplace_back(creature);
	creature->setPos(CREATURES_POSITION);
	creature->setZValue(1);
	scene->addItem(creature);
	return creature;
}

void Board::clearBoard()
{
	scene->clear();
	creatures.clear();
	dots.clear();
	walls.clear();
}

void Board::moveAll()
{
	for (auto& creature : creatures) {
		creature->moveMoveable(walls, spawnArea);
	}
	checkDotCollision();
	checkEating();
	checkGhostCollisions();
	checkWinConditions();
}

void Board::checkWinConditions()
{
	if (counter->getScore() >= MAX_SCORE) {
		counter->winner();
		gameEnd = true;
		gameTimer->stop();
	}	
}

void Board::defeat()
{
	counter->lose();
	gameEnd = true;
	gameTimer->stop();
}

void Board::checkEating()
{
	if (eating) {
		eatingTimeCounter++;
		if (eatingTimeCounter >= EATING_TIME) {
			eatingTimeCounter = 0;
			eating = false;
			for (auto& creature : creatures) {
				if (typeid(*creature) != typeid(PacMan)) {
					((Ghost*)creature)->setEscape(false);
					creature->setImage(DEFAULT);
				}
			}
		}
	}
}

void Board::checkGhostCollisions()
{
	QList<QGraphicsItem *> colliding = pacman->collidingItems();

	for (int i = 0, n = colliding.size(); i < n; i++) {
		if (dynamic_cast<Ghost*>(colliding[i])) {
			if (eating) ((Ghost*)colliding[i])->respawn();
			else defeat();
		}
	}
}

void Board::checkDotCollision()
{
	QList<QGraphicsItem *> colliding = pacman->collidingItems();

	for (int i = 0, n = colliding.size(); i < n; i++) {
		if (dynamic_cast<SmallDot*>(colliding[i])) {
			scene->removeItem(colliding[i]);
			counter->increase(SMALL_DOT_POINTS);
			delete colliding[i];
		} else if (dynamic_cast<BigDot*>(colliding[i]))
		{
			scene->removeItem(colliding[i]);
			bigDotCollected();
			delete colliding[i];
		}
	}
}

void Board::bigDotCollected()
{
	counter->increase(BIG_DOT_POINTS);
	eating = true;

	for (auto& creature : creatures) {
		if (typeid(*creature) != typeid(PacMan)) {
			((Ghost*)creature)->setEscape(true);
			creature->setImage(QString(GREY_IMG_FILE));
		}
	}
}

void Board::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Left) {
		pacman->setNext(LEFT);
	}
	else if (event->key() == Qt::Key_Right) {
		pacman->setNext(RIGHT);
	}
	else if (event->key() == Qt::Key_Up) {
		pacman->setNext(UP);
	}
	else if (event->key() == Qt::Key_Down) {
		pacman->setNext(DOWN);
	}
	else if ((event->key() == Qt::Key_R) && gameEnd) {
		restartGame();
	}
	else if (event->key() == Qt::Key_Escape) {
		exit(0);
	}
}

void Board::ghostThink()
{
	for (auto& creature : creatures) {
		if (typeid(*creature) != typeid(PacMan)) {
			((Ghost*)creature)->planNext(std::pair<int, int>(pacman->x(), pacman->y()), pacman->currentDirection);
		}
	}
}
