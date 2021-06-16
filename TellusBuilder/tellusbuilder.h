#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_tellusbuilder.h"
#include "tellus_project.h"


class TellusBuilder : public QMainWindow
{
    Q_OBJECT

public:
    TellusBuilder(QWidget *parent = Q_NULLPTR);

	/**\brief  get the pointer of project*/
    TellusProject* get_project(){ return &tellus_project_; }

    /**\brief  get the pointer of ui*/
	Ui::TellusBuilderClass* get_ui() { return &ui; }

	/** ui */
    void InitTreeView();
    void InitPreviewView();
    void InitDockView();
    void InitTabView();
    void InitLayout();
    void UpdateTreeView();
    void UpdatePreviewView();
    

private:
	/** main project*/
    TellusProject   tellus_project_;
	
private slots:
    void OnActionAddImages();
    void OnActionSfm();

    void OnActionDoubleClickedTreeImage(const QModelIndex& index);
private:
    Ui::TellusBuilderClass ui;

protected:
	void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
};

