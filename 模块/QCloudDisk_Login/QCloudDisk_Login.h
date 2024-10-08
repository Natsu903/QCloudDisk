#pragma once

#include <QtWidgets/QDialog>
#include "ui_QCloudDisk_Login.h"

class QCloudDisk : public QDialog
{
    Q_OBJECT

public:
    QCloudDisk(QWidget *parent = nullptr);
    ~QCloudDisk();

private:
    Ui::QCloudDiskClass ui;
};
