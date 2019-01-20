#include "GraphicSpawnItem.h"
#include <QPainter>

void GraphicSpawnItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QRectF rect = boundingRect();
	QBrush brush(Qt::gray);

	painter->fillRect(rect, brush);
	painter->drawRect(rect);
}