#pragma once
#include "GraphicDotItem.h"
#include "DotDrawer.h"
#include "Constants.h"
#include <QPainter>

class SmallDot :
	public GraphicDotItem
{
public:
	SmallDot(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = nullptr) : GraphicDotItem(x, y, width, height) {}
	virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr) override;

	virtual int getPoints() override;
};

