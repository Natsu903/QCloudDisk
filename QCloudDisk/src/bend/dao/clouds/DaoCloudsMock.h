#pragma once
#include "DaoClouds.h"
#include <QJsonValue>


class DaoCloudsMock:public DaoClouds
{
public:
	DaoCloudsMock(const QString& path);

	virtual QList<MyBucket> buckets();

private:
	QJsonValue m_mock;
};
