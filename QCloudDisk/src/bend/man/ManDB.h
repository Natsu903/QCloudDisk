#pragma once
#include <QObject>
#include "../dao/DaoLoginInfo.h"
#include "QList"
#include "QStringList"
class ManDB:public QObject
{
	Q_OBJECT
public:
	ManDB(QObject* parent = nullptr);

	static ManDB* instance();

	void init();

	void saveLoginInfo(const QString& name,const QString& id,const QString& key,const QString& remark);
	void removeLoginInfo(const QString& id);
	int getIndexByLoginInfo(const QString& secrecid);
	QStringList loginNameList();
	LoginInfo getLoginInfoByName(const QString& name);


private:
	DaoLoginInfo m_daoLoginInfo;
	QList<LoginInfo> m_loginInfoList;
};

