#include "./src/fend/uimain/UiMain.h"
#include <QtWidgets/QApplication>
#include "src/helper/FileHelper.h"
#include "src/bend/man/ManDB.h"
#include "src/bend/man/ManClouds.h"
#include "src/config/globals.h"
#include "src/plugins/manplugin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GLOBALS::init();
    ManPlugin::instance()->installPlugins();

    //读取文档中的qss
    QString qssStr = FileHelper::readAllText(":/static/qss/default.qss");
    a.setStyleSheet(qssStr);

    ManDB::instance()->init();

    UiMain w;
    w.showLoginDialog();
    //w.show();
    ManClouds::instance()->setBucket();
    return a.exec();
}
