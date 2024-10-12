#pragma once
#include <QString>

struct LoginInfo
{
	QString name;
	QString secret_id;
	QString secret_key;
	QString remark;
	uint timestamp;
};