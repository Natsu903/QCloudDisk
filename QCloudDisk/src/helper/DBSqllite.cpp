#include "DBSqllite.h"
#include <qDebug>
#include <QSqlError>
#include <QSqlRecord>>

DBSqllite::DBSqllite()
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
}

DBSqllite::~DBSqllite()
{
	if (m_db.isOpen())
	{
		m_db.close();
	}
}

void DBSqllite::connect(const QString & dbPath)
{
	m_db.setDatabaseName(dbPath);
	if (!m_db.open())
	{
		qDebug() << QString("打开数据库失败：%1 %2").arg(dbPath, m_db.lastError().text());
	}
}

QSqlQuery DBSqllite::exec(const QString& sql)
{
	QSqlQuery query;
	if (!query.exec(sql))
	{
		qDebug() << QString("执行sql语句失败：%1 %2").arg(sql, query.lastError().text());
	}
	return query;
}

bool DBSqllite::exists(const QString& sql)
{
	QSqlQuery query = exec(sql);
	return query.next();
}

QList<QMap<QString, QVariant>> DBSqllite::select(const QString& sql)
{
	QList<QMap<QString, QVariant>> retList;
	QSqlQuery query = exec(sql);
	while (query.next())
	{
		QMap<QString, QVariant> ret;
		QSqlRecord record = query.record();
		for (int i = 0; i < record.count(); ++i)
		{
			QString name = record.fieldName(i);
			QVariant value = record.value(i);
			ret[name] = value;
		}
		qDebug() << QString("查询出结果：") << ret;
		retList.append(ret);
	}
	return retList;
}
