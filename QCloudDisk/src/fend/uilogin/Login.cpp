#include "Login.h"
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>
#include "../../bend/man/ManDB.h"
#include <QCompleter>

Login::Login(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//隐藏默认的标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);

	//登录界面图标
	QPixmap pixmap(":/static/imgs/qtlogo.png");
	ui.label_logo->setPixmap(pixmap.scaled(ui.label_logo->size()));

	//设置样式
	ui.label_title->setProperty("style_font", "h3");
	ui.label_Connect->setProperty("style_font", "h4");
	ui.label_ID->setProperty("style_font", "h4");
	ui.label_Key->setProperty("style_font", "h4");
	ui.label_Remark->setProperty("style_font", "h4");
	ui.btn_exit->setProperty("style_font", "h4");
	ui.btn_Login->setProperty("style_font", "h4");

	//密码不允许粘贴
	ui.lineEdit_Key->installEventFilter(this);
}

void Login::btnLogin()
{
	if (ui.lineEdit_ID->text().trimmed() == "zhangsan" && ui.lineEdit_Key->text().trimmed() == "123")
	{
		emit accept();
		if (ui.checkBox_Remember->isChecked())
		{
			//保存会话，保存登录信息
			ManDB::instance()->saveLoginInfo(ui.lineEdit_Connect->text(), ui.lineEdit_ID->text(), ui.lineEdit_Key->text(), ui.lineEdit_Remark->text());
		}
		else
		{
			//删除登录信息
			ManDB::instance()->removeLoginInfo(ui.lineEdit_ID->text());
		}
		updateLoginInfo();
	}
	else
	{
		QMessageBox::warning(this, "登录失败", "账号(密码)输入错误");
	}
}

Login::~Login()
{}

void Login::updateLoginInfo()
{
	QStringList words = ManDB::instance()->loginNameList();
	QCompleter* completer = new QCompleter(words);
	ui.lineEdit_Connect->setCompleter(completer);
	connect(completer, static_cast<void (QCompleter::*)(const QString&)>(&QCompleter::activated), [&](const QString& name)
		{
			LoginInfo info = ManDB::instance()->getLoginInfoByName(name);
			ui.lineEdit_ID->setText((info.secret_id));
			ui.lineEdit_Key->setText((info.secret_key));
			ui.lineEdit_Remark->setText((info.remark));
			ui.checkBox_Remember->setChecked(true);
		});
}

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

bool Login::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == ui.lineEdit_Key)
	{
		if (event->type() == QEvent::KeyPress)
		{
			QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
			if (keyEvent->modifiers() == Qt::ControlModifier)
			{
				if (keyEvent->key() == Qt::Key_C || keyEvent->key() == Qt::Key_V)
				{
					return true;//返回true事件已经被处理不再往下传递
				}
			}
		}
	}
	return QDialog::eventFilter(watched, event);
}
