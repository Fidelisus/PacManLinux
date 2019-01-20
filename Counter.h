#pragma once
#include <QGraphicsTextItem>
#include "Constants.h"

class Counter : public QGraphicsTextItem {
public:
	Counter(QGraphicsItem * parent = 0);
	void increase(int value);
	int getScore();
	void restart();
	void winner();
	void lose();
private:
	int score;
};
