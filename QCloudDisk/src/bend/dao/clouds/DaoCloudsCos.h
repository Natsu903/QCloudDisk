#pragma once
#include "DaoClouds.h"
#include "cos_api.h"

class DaoCloudsCos :public DaoClouds
{
public:
	DaoCloudsCos();
	~DaoCloudsCos();

	QList<MyBucket> buckets() override;
	QList<MyBucket> login(const QString& secretId, const QString& secretKey)override ;

private:
	qcloud_cos::CosConfig* m_config = nullptr;
};
