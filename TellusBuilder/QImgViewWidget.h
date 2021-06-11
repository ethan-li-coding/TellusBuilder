#ifndef TELLUS_BUILDER_IMGVIEW_WIDGET_H
#define TELLUS_BUILDER_IMGVIEW_WIDGET_H

#include <qwidget.h>
#include <QImage>

// widget for displaying 2d image
class QImgViewWidget :
    public QWidget
{
public:
    QImgViewWidget() = default;
    ~QImgViewWidget() = default;

    /**\brief load image date from file path */
    void SetImage(const QString& img_path);

private:
    /* image data for displaying */
    QImage  img_displaying_;
    /* pixmap data for displaying */
    QPixmap pix_displaying_;

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif