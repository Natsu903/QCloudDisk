#include "FileHelper.h"
#include <QFile>
#include <QDebug>

FileHelper::FileHelper()
{
}

FileHelper::~FileHelper()
{
}

QString FileHelper::readAllText(const QString& filePath)
{
	QFile file(filePath);
	if (!file.exists())
	{
		qDebug() << "file not exists";
		return nullptr;
	}
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "file open error";
		return nullptr;
	}
	QByteArray data = file.readAll();
	file.close();
	return data;
}
