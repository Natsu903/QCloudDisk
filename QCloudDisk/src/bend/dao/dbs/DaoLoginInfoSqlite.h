#pragma once
#include "DaoLoginInfo.h"
#include "src/helper/DBSqllite.h"

class DaoLoginInfoSqlite :public DaoLoginInfo
{
public:
	DaoLoginInfoSqlite();
	~DaoLoginInfoSqlite();

	bool exists(const QString& secretID);
	void insert(const LoginInfo& info);
	void update(const LoginInfo& info);
	void remove(const QString& secretID);
	QList<LoginInfo> select();

	void connect();
	void createTable();

private:
	DBSqllite m_db;
};
