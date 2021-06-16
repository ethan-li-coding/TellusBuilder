#ifndef TELLUS_BUILDER_IMGVIEW_WIDGET_H
#define TELLUS_BUILDER_IMGVIEW_WIDGET_H

#include <qwidget.h>
#include <QImage>
#include <QImageReader>

// widget for displaying 2d image
class QImgViewWidget :
    public QWidget
{
public:
    QImgViewWidget();
    ~QImgViewWidget() = default;

    /**\brief load image date from file path */
    void SetImage(const QString& img_path);

    void ResetTransform();
private:
    /* image data for displaying */
    QImage  img_display_;
    /* image data for displaying */
    QImageReader  img_reader_;
    /* original pixmap data*/
    QPixmap pix_ori_;
    /* pixmap data for displaying */
	QPixmap pix_display_;

    QString img_path_;
	/* zoom scale controlled by mouse wheel */
    float   zoom_scale_;
	/* move step controlled by mouse moving*/
    QPoint  move_step_;
    bool    move_start_;
    bool    is_moving_;
    QPoint  mouse_point_;

protected: 
    void paintEvent(QPaintEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
};

#endif