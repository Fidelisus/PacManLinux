#include "GraphicBarrierItem.h"
#include <QPainter>

void GraphicBarrierItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QRectF rect = boundingRect();
	QBrush brush(Qt::blue);

	painter->fillRect(rect, brush);
	painter->drawRect(rect);
}
