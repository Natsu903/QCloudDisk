#pragma once
#include <QString>

class FileHelper
{
public:
	FileHelper();
	~FileHelper();

	static QString readAllText(const QString& filePath);
	static QVariant readAllJson(const QString& filePath);
	
	static QString joinPath(const QString& path1, const QString& path2);
	static bool mkPath(const QString& path);
};

