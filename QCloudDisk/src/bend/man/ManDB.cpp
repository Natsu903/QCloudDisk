#include "ManDB.h"
#include <QDateTime>

Q_GLOBAL_STATIC(ManDB, ins)

ManDB::ManDB(QObject* parent)
{
}

ManDB* ManDB::instance()
{
	return ins;
}

void ManDB::init()
{
	m_daoLoginInfo.connect();
	m_daoLoginInfo.createTable();
	m_loginInfoList = m_daoLoginInfo.select();
}

void ManDB::saveLoginInfo(const QString& name, const QString& id, const QString& key, const QString& remark)
{
	LoginInfo info;
	info.name = (name == "" ? id : name);
	info.secret_id = id.trimmed();
	info.secret_key = key.trimmed();
	info.remark = remark.trimmed();
	info.timestamp = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch();

	if (m_daoLoginInfo.exists(info.secret_id))
	{
		m_daoLoginInfo.update(info);
		m_loginInfoList[getIndexByLoginInfo(id)] = info;
	}
	else
	{
		m_daoLoginInfo.insert(info);
		m_loginInfoList.append(info);
	}
}

void ManDB::removeLoginInfo(const QString& id)
{
	if (m_daoLoginInfo.exists(id))
	{
		m_daoLoginInfo.remove(id);
		m_loginInfoList.removeAt(getIndexByLoginInfo(id));
	}
}

int ManDB::getIndexByLoginInfo(const QString& secrecid)
{
	for (int i = 0; i < m_loginInfoList.size(); ++i)
	{
		if (m_loginInfoList[i].secret_id == secrecid)
		{
			return i;
		}
	}
	qDebug() << QString("获取登录信息索引失败%1").arg(secrecid);
	return -1;
}

QStringList ManDB::loginNameList()
{
	QStringList words;
	for (auto & i : m_loginInfoList)
	{
		words.append(i.name);
	}
	return words;
}

LoginInfo ManDB::getLoginInfoByName(const QString& name)
{
	for (auto & i : m_loginInfoList)
	{
		if (i.name == name)
		{
			return i;
		}
	}
	qDebug() << QString("通过名称查找登录信息失败 %1").arg(name);
}

