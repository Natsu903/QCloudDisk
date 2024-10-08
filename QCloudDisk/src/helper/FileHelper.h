#pragma once
#include <QString>

class FileHelper
{
public:
	FileHelper();
	~FileHelper();

	static QString readAllText(const QString& filePath);
};

