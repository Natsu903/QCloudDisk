#include "UiMain.h"
#include "../uilogin/Login.h"
#include <QDebug>

UiMain::UiMain(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.splitter->setStretchFactor(0, 1);
	ui.splitter->setStretchFactor(1, 4);
}

UiMain::~UiMain()
{
	if (m_loginDialog)
	{
		delete m_loginDialog;
		m_loginDialog = nullptr;
	}
}

void UiMain::showLoginDialog()
{
	if (!m_loginDialog)
	{
		m_loginDialog = new Login();
		connect(m_loginDialog, &Login::accepted, this, &UiMain::show);
		connect(ui.widget_Tools, &ToolBarWidget::quitLogin, this, &UiMain::showLoginDialog);
	}
	hide();
	m_loginDialog->show();
}

