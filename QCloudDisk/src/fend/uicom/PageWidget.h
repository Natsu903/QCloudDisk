#pragma once

#include <QWidget>
#include "ui_PageWidget.h"

class PageWidget : public QWidget
{
	Q_OBJECT

public:
	PageWidget(QWidget *parent = nullptr);
	~PageWidget();

private:
	Ui::PageWidgetClass ui;
};
