#include "./src/fend/uimain/UiMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UiMain w;
    w.showLoginDialog();
    //w.show();
    return a.exec();
}
