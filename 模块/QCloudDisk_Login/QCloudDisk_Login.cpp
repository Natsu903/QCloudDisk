#include "QCloudDisk_Login.h"

QCloudDisk::QCloudDisk(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    QPixmap pixmap(":/imgs/qtlogo.png");
    ui.label_logo->setPixmap(pixmap.scaled(ui.label_logo->size()));
    ui.lineEdit_Key->setEchoMode(QLineEdit::Password);
}

QCloudDisk::~QCloudDisk()
{}
