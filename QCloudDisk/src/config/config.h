#pragma once
#include <QString>
#include <QDir>
#include "../helper/FileHelper.h"

namespace CONF
{
	namespace PATH
	{
		static const QString WORK = QDir::currentPath();
		static const QString SQL = FileHelper::joinPath(WORK, "static/sql");
	};

	namespace SQLITE
	{
		static const QString NAME = FileHelper::joinPath(PATH::SQL, "cos.db");
	};

	namespace SQL
	{
		static const QString LOGIN_INFO_TABLE = ":/static/sql/login_info.sql";
	};

	namespace TABLES
	{
		static const QString LOGIN_INFO = "login_info";
	};

	static bool init()
	{
		return FileHelper::mkPath(PATH::SQL);
	}
	static bool OK = init();
}
