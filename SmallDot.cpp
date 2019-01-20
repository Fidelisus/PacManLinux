#include "SmallDot.h"

void SmallDot::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	DotDrawer::drawDot(*painter, boundingRect(), SMALL_DOT_THICKNESS, Qt::darkMagenta);
}

int SmallDot::getPoints()
{
	return SMALL_DOT_POINTS;
}
