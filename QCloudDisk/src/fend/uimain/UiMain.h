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

private slots:
	void onButtonClicked(const QString& text);
	void onUpload();
	void onDownload();
	void onRefresh();
	void onUnLogin();
	
private:
	Ui::UiMainClass ui;
	Login* m_loginDialog = nullptr;
};

