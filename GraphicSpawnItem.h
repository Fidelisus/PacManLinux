#pragma once
#include <MyGraphicsRectItem.h>
class GraphicSpawnItem :
	public MyGraphicsRectItem
{
public:
	GraphicSpawnItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = nullptr) : MyGraphicsRectItem(x, y, width, height) {}
	virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = nullptr) override;
};

