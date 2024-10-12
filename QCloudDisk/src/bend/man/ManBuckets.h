#pragma once

#include <QObject>
#include <QStandardItemModel>

class ManBuckets  : public QObject
{
	Q_OBJECT

public:
	ManBuckets(QObject* parent = nullptr);
	~ManBuckets();

	static ManBuckets* instance();
	void setBucket();

	QStandardItemModel* model() const;

private:
	QStandardItemModel* m_model = nullptr;
};
