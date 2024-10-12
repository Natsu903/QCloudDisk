#include "./src/fend/uimain/UiMain.h"
#include <QtWidgets/QApplication>
#include "src/helper/FileHelper.h"
#include "src/bend/man/ManBuckets.h"
#include "src/bend/man/ManDB.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //读取文档中的qss
    QString qssStr = FileHelper::readAllText(":/static/qss/default.qss");
    a.setStyleSheet(qssStr);

    ManDB::instance()->init();

    UiMain w;
    w.showLoginDialog();
    //w.show();
    ManBuckets::instance()->setBucket();
    return a.exec();
}
