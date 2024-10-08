#pragma once

#include <QWidget>
#include "ui_ToolBarWidget.h"

class ToolBarWidget : public QWidget
{
	Q_OBJECT

public:
	ToolBarWidget(QWidget *parent = nullptr);
	~ToolBarWidget();

signals:
	void quitLogin();

public slots:
	void UploadFile();
	void DownloadFile();

private:
	Ui::ToolBarWidgetClass ui;
};
