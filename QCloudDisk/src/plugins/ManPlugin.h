#pragma once

#include <QObject>

class DaoClouds;
class Version;

class ManPlugin  : public QObject
{
	Q_OBJECT

public:
	ManPlugin(QObject *parent=nullptr);
	~ManPlugin();

	static ManPlugin* instance();

	DaoClouds* clouds();

	void installPlugins();

	DaoClouds* m_clouds;
	Version* m_version;
};
