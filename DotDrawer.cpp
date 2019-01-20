#include "DotDrawer.h"

void DotDrawer::drawDot(QPainter &painter,  QRectF size, int thickness, QColor color) {

	QRectF rect = size;

	painter.setBrush(QBrush(color));
	painter.drawEllipse(rect);
}