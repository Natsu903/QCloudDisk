#include "Login.h"
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>

Login::Login(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//隐藏默认的标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);

	//登录界面图标
	QPixmap pixmap(":/static/imgs/logo.png");
	ui.label_logo->setPixmap(pixmap.scaled(ui.label_logo->size()));

	//密码不允许粘贴
	ui.lineEdit_Key->installEventFilter(this);
}

void Login::btnLogin()
{
	if (ui.lineEdit_ID->text().trimmed() == "zhangsan" && ui.lineEdit_Key->text().trimmed() == "123")
	{
		emit accept();
	}
	else
	{
		QMessageBox::warning(this, "登录失败", "账号(密码)输入错误");
	}
}

Login::~Login()
{}

void Login::mousePressEvent(QMouseEvent * e)
{
	if (e->button() == Qt::LeftButton)
	{
		m_start = e->pos();
	}
	QDialog::mousePressEvent(e);
}

void Login::mouseMoveEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		QPoint targetPos = e->pos() - m_start + pos();
		this->move(targetPos);
	}
	QDialog::mouseMoveEvent(e);
}
