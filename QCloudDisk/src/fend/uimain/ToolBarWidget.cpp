#include "ToolBarWidget.h"
#include <qdebug.h>
#include <QFileDialog>
#include <QSignalMapper>

ToolBarWidget::ToolBarWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QSignalMapper* mapper = new QSignalMapper(this);
	QList<QPushButton*> buttonList = findChildren<QPushButton*>();
	for (auto btn : buttonList) {
		connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
		mapper->setMapping(btn, btn->text());
	}
	connect(mapper, QOverload<const QString&>::of(&QSignalMapper::mappedString), this, &ToolBarWidget::buttonClicked);
}

ToolBarWidget::~ToolBarWidget()
{}
