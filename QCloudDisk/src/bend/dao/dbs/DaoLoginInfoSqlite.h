#pragma once
#include "DaoLoginInfo.h"
#include "../../../helper/DBSqllite.h"

class DaoLoginInfoSqlite :public DaoLoginInfo
{
public:
	DaoLoginInfoSqlite();
	~DaoLoginInfoSqlite();

	bool exists(const QString& secretID) override;
	void insert(const LoginInfo& info) override;
	void update(const LoginInfo& info) override;
	void remove(const QString& secretID) override;
	QList<LoginInfo> select() override;

	void connect() override;
	void createTable() override;

private:
	DBSqllite m_db;
};
