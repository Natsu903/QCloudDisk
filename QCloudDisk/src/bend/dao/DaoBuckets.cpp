#include "DaoBuckets.h"
#include "../../helper/FileHelper.h"

#include <QVariant>
#include <QJsonArray>

DaoBuckets::DaoBuckets()
{
}

QList<MyBucket> DaoBuckets::bucketsFromMock(const QString& path)
{
	QList<MyBucket> res;
	QVariant var = FileHelper::readAllJson(path);
	if (var.isNull()) 
	{
		qDebug() << "QVariant 为空";
	}
	QJsonArray arr = var.toJsonArray();
	if (arr.isEmpty()) 
	{
		qDebug() << "QJsonArray 为空";
	}

	for (int i = 0; i < arr.count(); i++)
	{
		QJsonValue v = arr[i];
		MyBucket bucket;
		bucket.name = v["name"].toString();
		bucket.location = v["location"].toString();
		bucket.create_date = v["create_date"].toString();
		res.append(bucket);
	}
	return res;
}
