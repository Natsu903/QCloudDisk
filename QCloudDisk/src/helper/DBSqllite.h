#pragma once
#include <QString>
#include <QSqlDatabase>
#include "QSqlQuery"
#include "QList"
#include "QMap"
#include "QVariant"

class DBSqllite 
{
public:
	DBSqllite();
	~DBSqllite();

	void connect(const QString& dbPath);
	QSqlQuery exec(const QString& sql);
	bool exists(const QString& sql);
	QList<QMap<QString, QVariant>> select(const QString& sql);

private:
	QSqlDatabase m_db;
};
