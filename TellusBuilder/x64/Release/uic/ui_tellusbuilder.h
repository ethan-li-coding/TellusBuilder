/********************************************************************************
** Form generated from reading UI file 'tellusbuilder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELLUSBUILDER_H
#define UI_TELLUSBUILDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "qimgviewwidget.h"
#include "qmodelviewglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_TellusBuilderClass
{
public:
    QAction *action_sfm;
    QAction *action_addimages;
    QWidget *central_widget;
    QTabWidget *tab_mainview;
    QWidget *widget_model;
    QModelViewGLWidget *widget_gl_model;
    QImgViewWidget *widght_imgview;
    QTabWidget *tab_info;
    QWidget *widget_previews;
    QListWidget *list_previews;
    QWidget *widget_console;
    QMenuBar *menu_bar;
    QMenu *menu_file;
    QMenu *menu_builder;
    QStatusBar *status_bar;
    QDockWidget *dock_workspace;
    QWidget *widget_workspace;
    QTreeView *tree_images;
    QDockWidget *dock_log;
    QWidget *widget_log;

    void setupUi(QMainWindow *TellusBuilderClass)
    {
        if (TellusBuilderClass->objectName().isEmpty())
            TellusBuilderClass->setObjectName(QString::fromUtf8("TellusBuilderClass"));
        TellusBuilderClass->resize(2440, 1440);
        TellusBuilderClass->setStyleSheet(QString::fromUtf8("background-color: rgba(36, 36, 36, 255);"));
        action_sfm = new QAction(TellusBuilderClass);
        action_sfm->setObjectName(QString::fromUtf8("action_sfm"));
        action_addimages = new QAction(TellusBuilderClass);
        action_addimages->setObjectName(QString::fromUtf8("action_addimages"));
        central_widget = new QWidget(TellusBuilderClass);
        central_widget->setObjectName(QString::fromUtf8("central_widget"));
        central_widget->setStyleSheet(QString::fromUtf8(""));
        tab_mainview = new QTabWidget(central_widget);
        tab_mainview->setObjectName(QString::fromUtf8("tab_mainview"));
        tab_mainview->setGeometry(QRect(0, 0, 2000, 1091));
        tab_mainview->setFocusPolicy(Qt::TabFocus);
        tab_mainview->setAutoFillBackground(false);
        tab_mainview->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 80);"));
        tab_mainview->setTabPosition(QTabWidget::North);
        tab_mainview->setTabShape(QTabWidget::Rounded);
        tab_mainview->setUsesScrollButtons(false);
        tab_mainview->setDocumentMode(false);
        tab_mainview->setTabsClosable(false);
        tab_mainview->setMovable(false);
        tab_mainview->setTabBarAutoHide(false);
        widget_model = new QWidget();
        widget_model->setObjectName(QString::fromUtf8("widget_model"));
        widget_gl_model = new QModelViewGLWidget(widget_model);
        widget_gl_model->setObjectName(QString::fromUtf8("widget_gl_model"));
        widget_gl_model->setGeometry(QRect(0, 0, 300, 200));
        tab_mainview->addTab(widget_model, QString());
        widght_imgview = new QImgViewWidget();
        widght_imgview->setObjectName(QString::fromUtf8("widght_imgview"));
        tab_mainview->addTab(widght_imgview, QString());
        tab_info = new QTabWidget(central_widget);
        tab_info->setObjectName(QString::fromUtf8("tab_info"));
        tab_info->setGeometry(QRect(0, 1100, 2000, 221));
        tab_info->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 80);"));
        tab_info->setTabPosition(QTabWidget::South);
        widget_previews = new QWidget();
        widget_previews->setObjectName(QString::fromUtf8("widget_previews"));
        list_previews = new QListWidget(widget_previews);
        list_previews->setObjectName(QString::fromUtf8("list_previews"));
        list_previews->setGeometry(QRect(0, 0, 256, 192));
        list_previews->setFrameShape(QFrame::NoFrame);
        list_previews->setViewMode(QListView::IconMode);
        list_previews->setSelectionRectVisible(false);
        tab_info->addTab(widget_previews, QString());
        widget_console = new QWidget();
        widget_console->setObjectName(QString::fromUtf8("widget_console"));
        tab_info->addTab(widget_console, QString());
        TellusBuilderClass->setCentralWidget(central_widget);
        menu_bar = new QMenuBar(TellusBuilderClass);
        menu_bar->setObjectName(QString::fromUtf8("menu_bar"));
        menu_bar->setGeometry(QRect(0, 0, 2440, 33));
        menu_bar->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 36, 36);\n"
"padding: 5px;\n"
"color: rgb(255, 255, 255);"));
        menu_bar->setDefaultUp(false);
        menu_bar->setNativeMenuBar(true);
        menu_file = new QMenu(menu_bar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_builder = new QMenu(menu_bar);
        menu_builder->setObjectName(QString::fromUtf8("menu_builder"));
        TellusBuilderClass->setMenuBar(menu_bar);
        status_bar = new QStatusBar(TellusBuilderClass);
        status_bar->setObjectName(QString::fromUtf8("status_bar"));
        TellusBuilderClass->setStatusBar(status_bar);
        dock_workspace = new QDockWidget(TellusBuilderClass);
        dock_workspace->setObjectName(QString::fromUtf8("dock_workspace"));
        QFont font;
        font.setPointSize(9);
        dock_workspace->setFont(font);
        dock_workspace->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);\n"
"background-color: rgb(36, 36, 36);\n"
"border:1px;"));
        widget_workspace = new QWidget();
        widget_workspace->setObjectName(QString::fromUtf8("widget_workspace"));
        widget_workspace->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 80);\n"
"color: rgb(255, 255, 255);"));
        tree_images = new QTreeView(widget_workspace);
        tree_images->setObjectName(QString::fromUtf8("tree_images"));
        tree_images->setGeometry(QRect(0, 0, 261, 900));
        tree_images->setStyleSheet(QString::fromUtf8(""));
        tree_images->setFrameShape(QFrame::NoFrame);
        tree_images->setHeaderHidden(true);
        dock_workspace->setWidget(widget_workspace);
        TellusBuilderClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dock_workspace);
        dock_log = new QDockWidget(TellusBuilderClass);
        dock_log->setObjectName(QString::fromUtf8("dock_log"));
        dock_log->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);\n"
"background-color: rgb(36, 36, 36);\n"
"border:1px;"));
        widget_log = new QWidget();
        widget_log->setObjectName(QString::fromUtf8("widget_log"));
        widget_log->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 80);"));
        dock_log->setWidget(widget_log);
        TellusBuilderClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_log);
        dock_workspace->raise();
        dock_log->raise();

        menu_bar->addAction(menu_file->menuAction());
        menu_bar->addAction(menu_builder->menuAction());
        menu_file->addAction(action_addimages);
        menu_builder->addAction(action_sfm);

        retranslateUi(TellusBuilderClass);

        tab_mainview->setCurrentIndex(0);
        tab_info->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TellusBuilderClass);
    } // setupUi

    void retranslateUi(QMainWindow *TellusBuilderClass)
    {
        TellusBuilderClass->setWindowTitle(QApplication::translate("TellusBuilderClass", "TellusBuilder", nullptr));
        action_sfm->setText(QApplication::translate("TellusBuilderClass", "Structure From Motion", nullptr));
        action_addimages->setText(QApplication::translate("TellusBuilderClass", "Add Images", nullptr));
        tab_mainview->setTabText(tab_mainview->indexOf(widget_model), QApplication::translate("TellusBuilderClass", "Model", nullptr));
        tab_mainview->setTabText(tab_mainview->indexOf(widght_imgview), QApplication::translate("TellusBuilderClass", "Photo", nullptr));
        tab_info->setTabText(tab_info->indexOf(widget_previews), QApplication::translate("TellusBuilderClass", "Preiews", nullptr));
        tab_info->setTabText(tab_info->indexOf(widget_console), QApplication::translate("TellusBuilderClass", "Console", nullptr));
        menu_file->setTitle(QApplication::translate("TellusBuilderClass", "File", nullptr));
        menu_builder->setTitle(QApplication::translate("TellusBuilderClass", "Build", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TellusBuilderClass: public Ui_TellusBuilderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELLUSBUILDER_H
