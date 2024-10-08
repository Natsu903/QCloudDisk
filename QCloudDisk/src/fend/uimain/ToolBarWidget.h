#pragma once

#include <QWidget>
#include "ui_ToolBarWidget.h"

class ToolBarWidget : public QWidget
{
	Q_OBJECT

public:
	ToolBarWidget(QWidget *parent = nullptr);
	~ToolBarWidget();

private:
	Ui::ToolBarWidgetClass ui;
};
