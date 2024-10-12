#pragma once
#include "QList"
#include "src/middle/CloudModels.h"

class DaoClouds 
{
public:
	DaoClouds() {};
	~DaoClouds() {};

	virtual QList<MyBucket> buckets() = 0;
};
