#include "Counter.h"

#include <QFont>

Counter::Counter(QGraphicsItem *parent){
	score = 0;

	setPlainText(SCORE_STRING);
	setDefaultTextColor(Qt::blue);
	setFont(QFont(FONT_NAME, FONT_SIZE));
}

void Counter::increase(int value) {
	score += value;
	setPlainText(SCORE_STRING);
}

int Counter::getScore() {
	return score;
}

void Counter::restart()
{
	score = 0;
}

void Counter::winner()
{
	setPlainText(WIN_STRING);
}

void Counter::lose()
{
	setPlainText(LOSE_STRING);
}


