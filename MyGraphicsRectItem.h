#pragma once
#include <qgraphicsitem.h>
class MyGraphicsRectItem : public QGraphicsItem
{
public:
	MyGraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = nullptr);
	virtual QRectF boundingRect() const override;

private:
	qreal x;
	qreal y;
	qreal width;
	qreal height;
};

