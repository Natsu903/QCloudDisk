#include "ManPlugin.h"
#include "../bend/dao/clouds/DaoCloudsMock.h"
#include "../config/globals.h"
#include "../bend/dao/clouds/daocloudscos.h"

Q_GLOBAL_STATIC(ManPlugin,ins)
ManPlugin::ManPlugin(QObject *parent)
	: QObject(parent)
{
	installPlugins();
}

ManPlugin::~ManPlugin()
{
	if (m_clouds)
	{
		delete m_clouds;
		m_clouds = nullptr;
	}
	if (m_version)
	{
		delete m_version;
		m_version = nullptr;
	}

}

ManPlugin* ManPlugin::instance()
{
	return ins();
}

DaoClouds* ManPlugin::clouds()
{
	return m_clouds;
}

void ManPlugin::installPlugins()
{
	//m_clouds = new DaoCloudsMock(":/static/testing/business.json");
	m_clouds = new DaoCloudsCos();
}
