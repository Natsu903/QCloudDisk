#include "DaoLoginInfoSqlite.h"
#include "src/config/config.h"

DaoLoginInfoSqlite::DaoLoginInfoSqlite()
{}

DaoLoginInfoSqlite::~DaoLoginInfoSqlite()
{}

bool DaoLoginInfoSqlite::exists(const QString& secretID)
{
	QString sql = QString("select id from %1 where secret_id = '%2';").arg(CONF::TABLES::LOGIN_INFO, secretID);
	return m_db.exists(sql);
}

void DaoLoginInfoSqlite::insert(const LoginInfo& info)
{
	QString sql = QString("insert into %1 (name, secret_id, secret_key, remark, timestamp) values('%2', '%3', '%4', '%5', '%6');")
		.arg(CONF::TABLES::LOGIN_INFO, info.name, info.secret_id, info.secret_key, info.remark).arg(info.timestamp);
	m_db.exec(sql);
}

void DaoLoginInfoSqlite::update(const LoginInfo& info)
{
	QString sql = QString("update %1 set name= '%2',secret_key='%3',remark='%4',timestamp='%5' where secret_id='%6'")
		.arg(CONF::TABLES::LOGIN_INFO, info.name, info.secret_key, info.remark).arg(info.timestamp).arg(info.secret_id);
	m_db.exec(sql);
}

void DaoLoginInfoSqlite::remove(const QString& secretID)
{
	QString sql = QString("delete from %1 where secret_id='%2';").arg(CONF::TABLES::LOGIN_INFO, secretID);
	m_db.exec(sql);
}

QList<LoginInfo> DaoLoginInfoSqlite::select()
{
	QString sql = QString("select name,secret_id,secret_key,remark from %1 order by timestamp desc;").arg(CONF::TABLES::LOGIN_INFO);
	QList<LoginInfo> retList;
	QList<QMap<QString, QVariant>> recordList = m_db.select(sql);
	for (const auto& record : recordList)
	{
		LoginInfo info;
		info.name = record["name"].toString();
		info.secret_id = record["secret_id"].toString();
		info.secret_key = record["secret_key"].toString();
		info.remark = record["remark"].toString();
		retList.append(info);
	}
	return retList;
}

void DaoLoginInfoSqlite::connect()
{
	m_db.connect(CONF::SQLITE::NAME);
}

void DaoLoginInfoSqlite::createTable()
{
	QString sql = FileHelper::readAllText(CONF::SQL::LOGIN_INFO_TABLE);
	qDebug() << sql;
	m_db.exec(sql);
}