#pragma once

#include <QWidget>
#include "ui_BreadWidget.h"

class BreadWidget : public QWidget
{
	Q_OBJECT

public:
	BreadWidget(QWidget *parent = nullptr);
	~BreadWidget();

private:
	Ui::BreadWidgetClass ui;
};
