#include "ManBuckets.h"
#include "../dao/DaoBuckets.h"
#include <QDebug>

Q_GLOBAL_STATIC(ManBuckets, ins)

ManBuckets::ManBuckets(QObject* parent)
	: QObject(parent)
{
	m_model = new QStandardItemModel(this);
}

ManBuckets::~ManBuckets()
{}

ManBuckets* ManBuckets::instance()
{
	return ins();
}

void ManBuckets::setBucket()
{
	DaoBuckets dao;
	QList<MyBucket> buckets = dao.bucketsFromMock(":/static/testing/business.json");
	m_model->setRowCount(buckets.size());
	for (int i=0;i<buckets.size();i++)
	{
		const MyBucket& bucket = buckets[i];
		QModelIndex index0 = m_model->index(i, 0);
		m_model->setData(index0, bucket.name);
		m_model->setData(index0, QString("存储桶名称:%1").arg(bucket.name), Qt::ToolTipRole);

		QModelIndex index1 = m_model->index(i, 1);
		m_model->setData(index1, bucket.location);
		m_model->setData(index1, QString("位置:%1").arg(bucket.location), Qt::ToolTipRole);

		QModelIndex index2 = m_model->index(i, 2);
		m_model->setData(index2, bucket.create_date);
		m_model->setData(index2, QString("创建时间:%1").arg(bucket.create_date), Qt::ToolTipRole);
	}
	//按时间排序
	model()->sort(2, Qt::DescendingOrder);
}

QStandardItemModel* ManBuckets::model() const
{
	return m_model;
}
