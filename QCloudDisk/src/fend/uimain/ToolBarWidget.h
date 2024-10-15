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
	void buttonClicked(const QString& text);

private:
	Ui::ToolBarWidgetClass ui;
};
