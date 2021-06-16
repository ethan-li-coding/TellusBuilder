#include "QImgViewWidget.h"
#include <QPainter>
#include <QWheelEvent>

QImgViewWidget::QImgViewWidget()
{
    zoom_scale_ = 1.0f;
    move_start_ = false;
    is_moving_ = false;
}

void QImgViewWidget::SetImage(const QString& img_path)
{
	// reset the transformation
    ResetTransform();
    QSize view_size = size();
	// loading by QImage
    img_path_ = img_path;
	img_display_.load(img_path_);
    pix_ori_ = QPixmap::fromImage(img_display_);
	pix_display_ = pix_ori_.scaled(zoom_scale_ * size(), Qt::KeepAspectRatio);

	/* TODO(Ethan) loading by QImageReader, faster when loading but slow when zooming 
    img_reader_.setFileName(img_path);
    img_reader_.setAutoTransform(true);
	const QSize img_size = img_reader_.size();
	const QSize size_scale = img_size.scaled(size(), Qt::KeepAspectRatio);
    img_reader_.setScaledSize(size_scale);
    pix_display_ = QPixmap::fromImageReader(&img_reader_);
    */
}

void QImgViewWidget::ResetTransform()
{
    // reset the zoom scale and move step
    zoom_scale_ = 1.0f;     
    move_step_ = QPoint(0, 0);
}

void QImgViewWidget::paintEvent(QPaintEvent* event)
{
	// rander the loading image
	// TODO(Ethan): It's slow and memory confusing when zooming in
	QPainter painter(this);
	painter.drawPixmap(move_step_.x() +(width() - pix_display_.width()) / 2, move_step_ .y()+ (height() - pix_display_.height()) / 2, pix_display_);
}

void QImgViewWidget::wheelEvent(QWheelEvent* event)
{
	// zoom in and out when scrolling mouse
    if (event->delta() > 0) {
        zoom_scale_ *= 1.1;
    }
    else {
        zoom_scale_ *= 0.9;
    }
    // TODO(Ethan): It's slow and memory confusing when zooming in
	pix_display_ = pix_ori_.scaled(zoom_scale_ * size(), Qt::KeepAspectRatio);
    update();
}

void QImgViewWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        if (!move_start_) {
            move_start_ = true;
            is_moving_ = false;
            mouse_point_ = event->globalPos();
        }
    }
}

void QImgViewWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
    	  if(move_start_) {
              move_start_ = false;
              is_moving_ = false;
    	  }
    }
}

void QImgViewWidget::mouseMoveEvent(QMouseEvent* event)
{
	// move image when moving mouse
    if (move_start_) {
        const QPoint mos_pt = event->globalPos();
        move_step_ += mos_pt - mouse_point_;
        is_moving_ = true;
        mouse_point_ = mos_pt;
        repaint();
    }
}

void QImgViewWidget::resizeEvent(QResizeEvent* event)
{
    pix_display_ = pix_ori_.scaled(zoom_scale_ * size(), Qt::KeepAspectRatio);
    update();
}
