#pragma once

#include <QWidget>
#include "ui_UiMain.h"

class UiMain : public QWidget
{
	Q_OBJECT

public:
	UiMain(QWidget *parent = nullptr);
	~UiMain();

private:
	Ui::UiMainClass ui;
};
