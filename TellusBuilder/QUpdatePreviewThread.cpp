#include "QUpdatePreviewThread.h"
#include "tellus_utils.h"

void QUpdatePreviewThread::SlotAddPreview(const QPixmap& pixmap, const int& img_id)
{
	auto& ui = *builder_->get_ui();

	const auto all_images = builder_->get_project()->GetAllImages();
	if (img_id >= all_images.size()) {
		return;
	}

	auto list_preview = ui.list_previews;
	const QSize icon_sz = list_preview->iconSize();

	auto image = all_images[img_id];
	QListWidgetItem* list_item = new QListWidgetItem(QIcon(pixmap), str2qstr(image.get_name()));
	list_item->setSizeHint(QSize(icon_sz.width(), icon_sz.height() + 10));
	list_preview->insertItem(img_id, list_item);
	list_preview->repaint();
}

void QUpdatePreviewThread::run()
{
	if (builder_ == nullptr || builder_->get_project() == nullptr) {
		return;
	}
	auto& ui = *builder_->get_ui();

	const auto new_images = builder_->get_project()->GetNewAddingImages();
	if (new_images.empty()) {
		return;
	}
	const auto num_images = new_images.size();

	QImageReader reader;
	for (auto k = 0; k < num_images; k++) {
		auto image = new_images[k];
		// set image reader
		reader.setFileName(str2qstr(image.get_path()));
		reader.setAutoTransform(true);
		const QSize img_size = reader.size();
		const QSize icon_sz = ui.list_previews->iconSize();
		const QSize size_scale = img_size.scaled(icon_sz, Qt::KeepAspectRatio);
		reader.setScaledSize(size_scale);

		auto pixmap = QPixmap::fromImageReader(&reader);

		// add preview to widget
		emit SingalAddPreview(pixmap, image.get_id());
	}
}
