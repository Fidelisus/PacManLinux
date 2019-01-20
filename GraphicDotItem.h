#pragma once
#include <MyGraphicsRectItem.h>

class GraphicDotItem : public MyGraphicsRectItem
{
public:
	GraphicDotItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = nullptr) : MyGraphicsRectItem(x, y, width, height) {}
	virtual int getPoints() = 0;
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr) override;
};

