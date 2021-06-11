#include "QImgViewWidget.h"
#include <QPainter>

void QImgViewWidget::SetImage(const QString& img_path)
{
	img_displaying_.load(img_path);
	pix_displaying_ = QPixmap::fromImage(img_displaying_);
}

void QImgViewWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	//painter.drawImage(QPoint(10, 10), img_displaying_);

	QPixmap pixmap = pix_displaying_.scaled(size(), Qt::KeepAspectRatio);

	painter.drawPixmap((width() - pixmap.width()) / 2, (height() - pixmap.height()) / 2, pixmap);
}
