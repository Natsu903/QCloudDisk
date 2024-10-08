#include "ToolBarWidget.h"
#include <qdebug.h>
#include <QFileDialog>

ToolBarWidget::ToolBarWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.btn_Logout, &QPushButton::clicked, this, &ToolBarWidget::quitLogin);
}

void ToolBarWidget::UploadFile()
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
}

void ToolBarWidget::DownloadFile()
{
	QString path = QFileDialog::getSaveFileName(this, "下载", "./");
	if (path.isEmpty())
	{
		qDebug() << "error catalogue";
	}
	else
	{
		qDebug() << "catalogue,path= " << path.toLocal8Bit().data();
	}
}

ToolBarWidget::~ToolBarWidget()
{}
