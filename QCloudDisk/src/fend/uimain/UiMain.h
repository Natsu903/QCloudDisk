#pragma once

#include <QWidget>
#include "ui_UiMain.h"

class Login;

class UiMain : public QWidget
{
	Q_OBJECT

public:
	UiMain(QWidget *parent = nullptr);
	~UiMain();

	void showLoginDialog();
	
private:
	Ui::UiMainClass ui;
	Login* m_loginDialog = nullptr;
};

