#pragma once

#include <QDialog>
#include "ui_Login.h"

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();

	//重写
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	bool eventFilter(QObject* watched, QEvent* event) override;

public slots:
	//按下登录按键判断是否可以登录
	void btnLogin();

private:
	Ui::LoginClass ui;
	QPoint m_start;
};
