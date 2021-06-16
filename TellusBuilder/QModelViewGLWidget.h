#ifndef TELLUS_BUILDER_MODELVIEW_GL_WIDGET_H
#define TELLUS_BUILDER_MODELVIEW_GL_WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

// Render widget for  3d model 
class QModelViewGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	QModelViewGLWidget(QWidget* parent) :QOpenGLWidget(parent) {}
	~QModelViewGLWidget();

private:

protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;
};


#endif