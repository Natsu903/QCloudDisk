#include "FileHelper.h"
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QVariant>
#include "QDir"
#include <QRegularExpression>

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

QVariant FileHelper::readAllJson(const QString& filePath)
{
	QString data = FileHelper::readAllText(filePath);
	QJsonDocument doc = QJsonDocument::fromJson(data.toLocal8Bit());
	return doc.toVariant();
}

QString FileHelper::joinPath(const QString& path1, const QString& path2)
{
	QString path = path1 + "/" + path2;
	QStringList pathList = path.split(QRegularExpression("[/\\\\]"), Qt::SkipEmptyParts);
	path = pathList.join("/");
	return QDir::cleanPath(path);
}

bool FileHelper::mkPath(const QString& path)
{
	QDir dir;
	return dir.mkpath(path);
}
