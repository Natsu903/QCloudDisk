#include "DaoCloudsMock.h"
#include <QJsonArray>
#include "src/helper/FileHelper.h"

DaoCloudsMock::DaoCloudsMock(const QString& path)
{
	m_mock = FileHelper::readAllJson(path).toJsonValue();
}

QList<MyBucket> DaoCloudsMock::buckets()
{
	QList<MyBucket> res;
	QJsonArray arr = m_mock["buckets"].toArray();
	for (int i = 0; i < arr.count(); i++)
	{
		QJsonValue v = arr[i];
		MyBucket bucket;
		bucket.name = v["name"].toString();
		bucket.location = v["location"].toString();
		bucket.create_date = v["create_date"].toString();
		res.append(bucket);
		qDebug() << bucket.name << bucket.location << bucket.create_date;
	}
	return res;
}
