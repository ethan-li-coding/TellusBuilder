#include "tellusbuilder.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextCodec>
#include <QStandardItemModel>
#include <QPainter>
#include <QGridLayout>

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
	
	InitLayout();

	connect(ui.action_addimages, SIGNAL(triggered()), this, SLOT(OnActionAddImages()));
	connect(ui.tree_images, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnActionDoubleClickedTreeImage(const QModelIndex& )));
}

void TellusBuilder::InitTreeView()
{
	// create model for tree 
	auto tree_imgs = ui.tree_images;
	auto* model = new QStandardItemModel(tree_imgs);
	tree_imgs->setModel(model);
	model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Images"));
	tree_imgs->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tree_imgs->setMaximumSize(300, 900);
}


void TellusBuilder::UpdateTreeView()
{
	const auto all_images = tellus_project_.GetAllImages();
	if(all_images.empty()) {
		return;
	}
	const auto num_images = all_images.size();

	// 
	auto* tree = ui.tree_images;
	auto* model = static_cast<QStandardItemModel*>(tree->model());
	QString str_title = QString("All Images (%1 Images)").arg(num_images);
	model->setItem(0, 0, new QStandardItem(str_title));

	// add name of images to tree
	for(auto image:all_images) {
		model->item(0, 0)->setChild(image.get_id(), 0, new QStandardItem(str2qstr(image.get_name())));
	}

	tree->setExpanded(model->index(0,0), true);
	auto workspace = static_cast<QDockWidget*>(ui.dock_workspace);
	auto ws_size = workspace->frameSize();
	tree->setFixedWidth(ws_size.width());
}

void TellusBuilder::InitDockView()
{
	// initializing dockpane, including workspace and...
	auto workspace = (QDockWidget*)ui.dock_workspace;
	workspace->setWindowTitle("Workspace");
	addDockWidget(Qt::LeftDockWidgetArea, workspace);
	workspace->setMaximumSize(300, 1320);
	workspace->setMinimumSize(300, 1320);
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
							QTabBar::tab{width:50px;height:22px; background-color:rgb(36,36,36); color:rgb(200,200,200); margin-right: 2px; margin-bottom:-2px;}\
							QTabBar::tab:selected{border:1px;border-bottom-color: none; background-color:rgb(50,50,50)}\
							QTabBar::tab:!selected{border-bottom: 3px;}\
                        ");

	auto wid_model = ui.widget_model;
	wid_model->setStyleSheet(" background-color:rgb(80,80,80);");
	auto wid_image = ui.widght_imgview;
	wid_image->setStyleSheet(" background-color:rgb(80,80,80);");

	// style sheet for photos/console widgets
	auto tab_info = ui.tab_info;
	tab_info->setStyleSheet("QTabWidget:pane{ border: 1px ;}\
							QTabBar::tab{width:60px;height:22px; background-color:rgb(36,36,36); color:rgb(200,200,200); margin-right: 2px; margin-bottom:-2px;}\
							QTabBar::tab:selected{border:1px;border-bottom-color: none; background-color:rgb(50,50,50)}\
							QTabBar::tab:!selected{border-bottom: 3px;}\
                        ");
	auto wid_previews = ui.widget_previews;
	wid_previews->setStyleSheet(" background-color:rgb(80,80,80);");
	auto wid_console = ui.widget_console;
	wid_console->setStyleSheet(" background-color:rgb(80,80,80);");

}

void TellusBuilder::InitLayout()
{
	//auto layout = ui.layout_main;

	//auto workspace_view = (QDockWidget*)ui.dock_workspace;
	//auto tab_view = ui.tab_mainview;

	//layout->setSpacing(5);
	//layout->addWidget((QWidget*)workspace_view, 0, 0);
	//layout->addWidget((QWidget*)tab_view, 0, 1);
	////layout->addWidget((QWidget*)out_view, 1, 1);

	//layout->setRowStretch(0, 1);
	//layout->setRowStretch(1, 4);
	//layout->setColumnStretch(0, 1);
	//layout->setColumnStretch(1, 2);

	//setLayout(layout);
}

void TellusBuilder::OnActionAddImages()
{
    QStringList file_paths = QFileDialog::getOpenFileNames(this,
        tr("Image Path"),
        "Data\\",
        tr("Image Files(*png *jpg);"));

	// add images in sequence
	for(auto path: file_paths) {
        tellus_project_.AddImage(qstr2str(path));
	}

	// update tree view for loaded images
	UpdateTreeView();
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
}

void TellusBuilder::paintEvent(QPaintEvent* event)
{
}
