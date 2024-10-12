#pragma once
#include "../../helper/DBSqllite.h"
#include "../models/DBModels.h"
#include "QList"

class DaoLoginInfo 
{
public:
	DaoLoginInfo();
	~DaoLoginInfo();

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
