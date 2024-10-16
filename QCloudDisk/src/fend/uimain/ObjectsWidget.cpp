#include "ObjectsWidget.h"
#include "../uidelegates/BucketDelegate.h"
#include "../../bend/man/ManClouds.h"

ObjectsWidget::ObjectsWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.table_Object->setModel(ManClouds::instance()->model());

	//设置第二列为combox操作
	ui.table_Object->setItemDelegateForColumn(1, new BucketDelegate());

	//设置表格水平标题内容
	QStandardItemModel* model = ManClouds::instance()->model();
	QStringList labels;
	labels << QString("名称")
		<< QString("地区")
		<< QString("创建时间");
	model->setColumnCount(labels.size());
	model->setHorizontalHeaderLabels(labels);

	//设置列宽度
	ui.table_Object->setColumnWidth(0, 200);
	ui.table_Object->setColumnWidth(1, 120);
	//最后一列占满整个表
	ui.table_Object->horizontalHeader()->setStretchLastSection(true);

	//隐藏垂直标题
	ui.table_Object->verticalHeader()->setHidden(true);

	//设置鼠标点击排序
	ui.table_Object->setSortingEnabled(true);
}

ObjectsWidget::~ObjectsWidget()
{}
