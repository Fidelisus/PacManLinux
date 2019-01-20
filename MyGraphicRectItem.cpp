#include "MyGraphicsRectItem.h"

MyGraphicsRectItem::MyGraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

QRectF MyGraphicsRectItem::boundingRect() const
{
	return QRectF(x, y, width, height);
}


