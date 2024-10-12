#pragma once
#include "QList"
#include "src/middle/DBModels.h"
#include "src/helper/DBSqllite.h"

class DaoLoginInfo 
{
public:
	DaoLoginInfo() {};
	~DaoLoginInfo() {};

	virtual bool exists(const QString& secretID) = 0;
	virtual void insert(const LoginInfo& info) = 0;
	virtual void update(const LoginInfo& info) = 0;
	virtual void remove(const QString& secretID) = 0;
	virtual QList<LoginInfo> select() = 0;

	virtual void connect()=0;
	virtual void createTable() = 0;								

};
