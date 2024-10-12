#include "BucketsWidget.h"
#include "../../bend/man/ManBuckets.h"

BucketsWidget::BucketsWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.list_Bucket->setModel(ManBuckets::instance()->model());
}

BucketsWidget::~BucketsWidget()
{}
