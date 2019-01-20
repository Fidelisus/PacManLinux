#include "BigDot.h"

void BigDot::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	DotDrawer::drawDot(*painter, boundingRect(), BIG_DOT_THICKNESS, Qt::darkCyan);
}

int BigDot::getPoints()
{
	return BIG_DOT_POINTS;
}

