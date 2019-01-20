#include "GraphicDotItem.h"

#include <QPainter>

void GraphicDotItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QRectF rect = boundingRect();
	QBrush brush(Qt::blue);

	painter->fillRect(rect, brush);
	painter->drawRect(rect);
}
