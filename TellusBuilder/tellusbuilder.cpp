#include "tellusbuilder.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextCodec>
#include <QStandardItemModel>
#include <QPainter>
#include <QResizeEvent>
#include <QGridLayout>
#include <QThread>
#include "QUpdatePreviewThread.h"

#include "tellus_utils.h"

TellusBuilder::TellusBuilder(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	setWindowState(Qt::WindowMaximized);

	// initializing ui
	InitDockView();
	InitTreeView();
	InitTabView();
	InitPreviewView();

	InitLayout();

	connect(ui.action_addimages, SIGNAL(triggered()), this, SLOT(OnActionAddImages()));
	connect(ui.tree_images, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnActionDoubleClickedTreeImage(const QModelIndex& )));
	connect(ui.list_previews, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(OnActionDoubleClickedTreeImage(const QModelIndex&)));
}

void TellusBuilder::InitTreeView()
{
	// initialize tree view for loaded images
	auto tree_imgs = ui.tree_images;
	auto* model = new QStandardItemModel(tree_imgs);
	tree_imgs->setModel(model);
	model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Images"));
	tree_imgs->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void TellusBuilder::InitPreviewView()
{
	// initialize preview view for loaded images
	auto list_preview = ui.list_previews;
	list_preview->setIconSize(QSize(100,100));
	list_preview->setResizeMode(QListView::Adjust);
	list_preview->setViewMode(QListView::IconMode);
	list_preview->setMovement(QListView::Static);
	list_preview->setSpacing(10);
}


void TellusBuilder::UpdateTreeView()
{
	// uodate tree view after related actions. eg. loading images
	const auto all_images = tellus_project_.GetAllImages();
	const auto new_images = tellus_project_.GetNewAddingImages();
	if(new_images.empty()) {
		return;
	}
	const auto num_allimages = all_images.size();
	const auto num_images = new_images.size();

	// 
	auto* tree = ui.tree_images;
	auto* model = static_cast<QStandardItemModel*>(tree->model());
	QString str_title = QString("All Images (%1 Images)").arg(num_allimages);
	if (model->item(0, 0) == nullptr) {
		model->setItem(0, 0, new QStandardItem(str_title));
	}
	else {
		auto item = model->item(0, 0);
		item->setText(str_title);
	}

	// add name of images to tree
	for(auto image:new_images) {
		model->item(0, 0)->setChild(image.get_id(), 0, new QStandardItem(str2qstr(image.get_name())));
	}

	tree->setExpanded(model->index(0,0), true);
	auto workspace = static_cast<QDockWidget*>(ui.dock_workspace);
	auto ws_size = workspace->frameSize();
	tree->setFixedWidth(ws_size.width());
}

void TellusBuilder::UpdatePreviewView()
{
	auto tab_info = ui.tab_info;
	tab_info->setCurrentIndex(0);

	// start thread for creating previews
	QUpdatePreviewThread* thread = new QUpdatePreviewThread(this);
	thread->start();
}

void TellusBuilder::InitDockView()
{
	// initializing dockpane, including workspace and...
	// dockpane widget of workspace
	auto dp_workspace = (QDockWidget*)ui.dock_workspace;
	dp_workspace->setWindowTitle("Workspace");
	addDockWidget(Qt::LeftDockWidgetArea, dp_workspace);

	// dockpane widget of log 
	auto dp_log = (QDockWidget*)ui.dock_log;
	dp_log->setWindowTitle("Log");
	addDockWidget(Qt::RightDockWidgetArea, dp_log);
}

void TellusBuilder::InitTabView()
{
	// initializing tab view for displaying 3d model and 2d images
	// get size of main widgets
	auto workspace = (QDockWidget*)ui.dock_workspace;
	auto ws_rect = workspace->geometry();
	auto fm_rect = geometry();

	// style sheet for 3d/2d widgets
	auto tab_view = ui.tab_mainview;
	tab_view->setStyleSheet("QTabWidget:pane{ border: 1px ;}\
							QTabBar::tab{width:50px;height:28px; background-color:rgb(36,36,36); color:rgb(200,200,200); margin-right: 2px; margin-bottom:-2px;}\
							QTabBar::tab:selected{border:1px;border-bottom-color: none; background-color:rgb(50,50,50)}\
							QTabBar::tab:!selected{border-bottom: 3px;}\
                        ");
	tab_view->setCurrentIndex(0);

	auto wid_model = ui.widget_model;
	wid_model->setStyleSheet(" background-color:rgb(80,80,80);");
	auto wid_image = ui.widght_imgview;
	wid_image->setStyleSheet(" background-color:rgb(80,80,80);");

	// style sheet for photos/console widgets
	auto tab_info = ui.tab_info;
	tab_info->setStyleSheet("QTabWidget:pane{ border: 1px ;}\
							QTabBar::tab{width:60px;height:28px; background-color:rgb(36,36,36); color:rgb(200,200,200); margin-right: 2px; margin-bottom:-2px;}\
							QTabBar::tab:selected{border:1px;border-bottom-color: none; background-color:rgb(50,50,50)}\
							QTabBar::tab:!selected{border-bottom: 3px;}\
                        ");

	auto wid_previews = ui.widget_previews;
	wid_previews->setStyleSheet(" background-color:rgb(80,80,80);");
	auto wid_console = ui.widget_console;
	wid_console->setStyleSheet(" background-color:rgb(80,80,80);");
	tab_info->setCurrentIndex(1);
}

void TellusBuilder::InitLayout()
{
}

void TellusBuilder::OnActionAddImages()
{
    QStringList file_paths = QFileDialog::getOpenFileNames(this,
        tr("Image Path"),
        "Data\\",
        tr("Image Files(*png *jpg);"));

	// add images in sequence
	vector<string> str_paths;
	for(auto path: file_paths) {
		str_paths.push_back(qstr2str(path));
	}
	tellus_project_.AddImages(str_paths);
	// update tree view for loaded images
	UpdateTreeView();
	// update preview view for loaded images
	UpdatePreviewView();
}

void TellusBuilder::OnActionSfm()
{
}

void TellusBuilder::OnActionDoubleClickedTreeImage(const QModelIndex& index)
{
	QMessageBox msg_box;
	
	auto* tree = ui.tree_images;
	auto* model = static_cast<QStandardItemModel*>(tree->model());
	unsigned img_id =  index.row();

	const auto all_images = tellus_project_.GetAllImages();
	if(img_id >= all_images.size()){
		msg_box.setText("data error!");
		msg_box.exec();
		return;
	}

	// get clicked image path 
	auto image = all_images[img_id];
	auto imgpath = str2qstr(image.get_path());
	
	// repaint
	auto img_view = ui.widght_imgview;
	img_view->SetImage(imgpath);
	img_view->repaint();

	// active 2d view
	auto tab_view = ui.tab_mainview;
	tab_view->setCurrentIndex(1);
	//tab_view->setTabText(1, str2qstr(image.get_name()));
}

void TellusBuilder::paintEvent(QPaintEvent* event)
{
}

void TellusBuilder::resizeEvent(QResizeEvent* event)
{
	// resize all widgets automatically

	const QSize size = event->size();
	const QRect frame_geometry = ui.central_widget->geometry();
	const QSize frame_size = ui.central_widget->size();
	const QSize menu_size = ui.menu_bar->size();

	// h1|h2|h3
	// v1
	// ¡ª¡ª
	// v2
	QSize layout_h1(menu_size.width() * 0.12, frame_size.height()),
		layout_h2(menu_size.width() * 0.76, frame_size.height()),
		layout_h3(menu_size.width() * 0.12, frame_size.height());
	QSize layout_v1(menu_size.width(), frame_size.height()*0.8),
		layout_v2(menu_size.width(), frame_size.height()*0.2);

	// workspace
	ui.dock_workspace->setMinimumWidth(layout_h1.width());
	ui.dock_workspace->setMaximumHeight(frame_size.height());

	// main view(model and image)
	ui.tab_mainview->setFixedSize(layout_h2.width() - 10, layout_v1.height());
	QSize tab_bar_sz = ui.tab_mainview->tabBar()->size();
	ui.widget_model->setFixedSize(layout_h2.width() - 10, layout_v1.height() - tab_bar_sz.height());
	ui.widght_imgview->setFixedSize(layout_h2.width() - 10, layout_v1.height() - tab_bar_sz.height());
	ui.widget_gl_model->setFixedSize(layout_h2.width() - 10, layout_v1.height() - tab_bar_sz.height());

	// info view(photos and console)
	QRect view_rt = ui.tab_mainview->frameGeometry();
	ui.tab_info->setGeometry(view_rt.x(), view_rt.y() + view_rt.height()+5, layout_h2.width() - 10, layout_v2.height());
	auto tab_sz = ui.tab_info->size();
	tab_bar_sz = ui.tab_info->tabBar()->size();
	ui.list_previews->setGeometry(0, 0, tab_sz.width(), tab_sz.height()- tab_bar_sz.height());

	// log view
	ui.dock_log->setMinimumWidth(layout_h3.width());
	ui.dock_log->setMaximumHeight(frame_size.height());

	setMinimumSize(500, 500);
}
