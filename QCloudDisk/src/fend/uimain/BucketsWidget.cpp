#include "BucketsWidget.h"
#include "../../bend/man/ManClouds.h"

BucketsWidget::BucketsWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.list_Bucket->setModel(ManClouds::instance()->model());
}

BucketsWidget::~BucketsWidget()
{}
