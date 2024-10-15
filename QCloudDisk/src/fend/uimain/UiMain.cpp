#include "UiMain.h"
#include "../uilogin/Login.h"
#include <QDebug>
#include "QFileDialog"

UiMain::UiMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.splitter->setStretchFactor(0, 1);
	ui.splitter->setStretchFactor(1, 3);
	connect(ui.widget_Tools, &ToolBarWidget::buttonClicked, this, &UiMain::onButtonClicked);
}

UiMain::~UiMain()
{
	if (m_loginDialog)
	{
		delete m_loginDialog;
		m_loginDialog = nullptr;
	}
}

void UiMain::showLoginDialog()
{
	if (!m_loginDialog)
	{
		m_loginDialog = new Login();
		m_loginDialog->updateLoginInfo();
		connect(m_loginDialog, &Login::accepted, this, &UiMain::show);
	}
	hide();
	m_loginDialog->show();
}

void UiMain::onButtonClicked(const QString& text)
{
	qDebug() << text;
	if (text == QString("上传"))
	{
		onUpload();
	}
	else if (text == QString("退出登录"))
	{
		onUnLogin();
	}
}

void UiMain::onUpload()
{
		//上传文件
	QStringList path = QFileDialog::getOpenFileNames(this, "上传", "./");
	if (path.isEmpty())
	{
		qDebug() << "Open File error";
	}
	else
	{
		for (int i = 0; i < path.count(); i++)
		{
			qDebug() << "Open File success,path= " << path[i].toLocal8Bit().data();
		}
	}
	qDebug() << "onUpload";
}

void UiMain::onDownload()
{
	/*QString path = QFileDialog::getSaveFileName(this, "下载", "./");
	if (path.isEmpty())
	{
		qDebug() << "error catalogue";
	}
	else
	{
		qDebug() << "catalogue,path= " << path.toLocal8Bit().data();
	}*/
	qDebug() << "onDownload";
}

void UiMain::onRefresh()
{
	qDebug() << "onRefresh";
}

void UiMain::onUnLogin()
{
	showLoginDialog();
}

