#include "QCloudDisk_Login.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCloudDisk w;
    w.show();
    return a.exec();
}
