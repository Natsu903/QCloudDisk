#include "UiMain.h"

UiMain::UiMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.splitter->setStretchFactor(0, 1);
	ui.splitter->setStretchFactor(1, 4);
}

UiMain::~UiMain()
{}
