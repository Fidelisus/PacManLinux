#pragma once

#include <QPainter>

class DotDrawer
{
public:
	static void drawDot(QPainter &painter,  QRectF size, int thickness, QColor color);
};

