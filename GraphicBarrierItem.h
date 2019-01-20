#pragma once

#include <MyGraphicsRectItem.h>

class GraphicBarrierItem : public MyGraphicsRectItem
{
public:
	GraphicBarrierItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = nullptr) : MyGraphicsRectItem(x, y, width, height){}
	virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr) override;
};

