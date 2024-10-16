#include "DaoCloudsCos.h"
#include <QDebug>
#include <QDir>

using namespace qcloud_cos;


DaoCloudsCos::DaoCloudsCos()
{
	qDebug() << "Current working directory:" << QDir::currentPath();
	m_config=new CosConfig("./static/cosconfig/cosconfig.json");
}

DaoCloudsCos::~DaoCloudsCos()
{
	if (m_config)
	{
		delete m_config;
		m_config = nullptr;
	}
}

QList<MyBucket> DaoCloudsCos::buckets()
{
	QList<MyBucket> res;

	GetServiceReq req;
	GetServiceResp resp;
	CosAPI cos = CosAPI(*m_config);
	CosResult result = cos.GetService(req, &resp);

	std::vector<Bucket> bs = resp.GetBuckets();
	for (std::vector<Bucket>::const_iterator itr = bs.begin(); itr != bs.end(); ++itr)
	{
		const Bucket& v = *itr;

		MyBucket b;
		b.name = QString(v.m_name.c_str());
		b.location = QString(v.m_location.c_str());
		b.create_date = QString(v.m_create_date.c_str());
		res.append(b);
	}
	return res;
}

QList<MyBucket> DaoCloudsCos::login(const QString& secretId, const QString& secretKey)
{
	m_config->SetAccessKey(secretId.toStdString());
	m_config->SetSecretKey(secretKey.toStdString());
	m_config->SetRegion("ap-shanghai");

	return buckets();
}
