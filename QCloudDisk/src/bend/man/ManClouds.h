#pragma once

#include <QObject>
#include <QStandardItemModel>

class ManClouds : public QObject
{
	Q_OBJECT

public:
	ManClouds(QObject* parent = nullptr);
	~ManClouds();

	static ManClouds* instance();
	void setBucket();

	QStandardItemModel* model() const;

private:
	QStandardItemModel* m_model = nullptr;
};
