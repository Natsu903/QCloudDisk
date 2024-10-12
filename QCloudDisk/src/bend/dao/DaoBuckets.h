#pragma once
#include <QList>
#include "../models/MyBucket.h"

class DaoBuckets
{
public:
	DaoBuckets();

	QList<MyBucket> bucketsFromMock(const QString& path);
};
