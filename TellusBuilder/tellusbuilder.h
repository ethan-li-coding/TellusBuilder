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

	/** ui */
    void InitTreeView();
    void UpdateTreeView();
    void InitDockView();
    void InitTabView();
    void InitLayout();

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
};
