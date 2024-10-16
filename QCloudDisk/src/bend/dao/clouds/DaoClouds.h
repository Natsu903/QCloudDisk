#pragma once
#include "QList"
#include "../../../middle/models/CloudModels.h"

class DaoClouds 
{
public:
	DaoClouds() {};
	~DaoClouds() {};

	virtual QList<MyBucket> buckets() = 0;
	virtual QList<MyBucket> login(const QString& secretId, const QString& secretKey) = 0;
};
