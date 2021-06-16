#ifndef TELLUS_BUILDER_PREVIEW_H
#define TELLUS_BUILDER_PREVIEW_H
#include <QThread>
#include "tellusbuilder.h"

// Thread for adding preview in the background
class QUpdatePreviewThread : public QThread
{
	Q_OBJECT

public:
	QUpdatePreviewThread(TellusBuilder* builder) {
		builder_ = builder;
		connect(this, SIGNAL(SingalAddPreview(const QPixmap&, const int&)), this, SLOT(SlotAddPreview(const QPixmap&, const int&)));
	}

signals:
	void SingalAddPreview(const QPixmap& pixmap, const int& img_id);

private slots:
	void SlotAddPreview(const QPixmap& pixmap, const int& img_id);

protected:
	void run() override;

private:
	TellusBuilder*	builder_;
};

#endif