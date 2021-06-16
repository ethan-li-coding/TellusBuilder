#include "QModelViewGLWidget.h"


QModelViewGLWidget::~QModelViewGLWidget()
{
}

void QModelViewGLWidget::initializeGL()
{
	// initialize conetext
	initializeOpenGLFunctions();
	glClearColor(80 / 255.0f, 80 / 255.0f, 80 / 255.0f, 1.0f);
}

void QModelViewGLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}

void QModelViewGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
