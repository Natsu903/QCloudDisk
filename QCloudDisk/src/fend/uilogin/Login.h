#pragma once

#include <QDialog>
#include "ui_Login.h"

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = nullptr);
	~Login();

	void updateLoginInfo();

	//重写
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	bool eventFilter(QObject* watched, QEvent* event) override;

public slots:
	//登录信息验证，连接数据库
	void btnLogin();

private:
	Ui::LoginClass ui;
	QPoint m_start;
};
