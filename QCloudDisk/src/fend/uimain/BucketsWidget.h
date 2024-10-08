#pragma once

#include <QWidget>
#include "ui_BucketsWidget.h"

class BucketsWidget : public QWidget
{
	Q_OBJECT

public:
	BucketsWidget(QWidget *parent = nullptr);
	~BucketsWidget();

private:
	Ui::BucketsWidgetClass ui;
};
