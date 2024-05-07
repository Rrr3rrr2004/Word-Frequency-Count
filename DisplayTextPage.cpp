#include "DisplayTextPage.h"
#include "MainWindow.h"

DisplayTextPage::DisplayTextPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DisplayTextPageClass())
{
	ui->setupUi(this);
	displayPara();
	//connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations1()));
}

void DisplayTextPage::displayPara()
{
	ui->display->setText("hello");
}

//have a change in text "Do you want to return to the operations menu?"
void DisplayTextPage::moveToOperations1()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to return to the operations menu?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		hide();
		operationsPage = new OperationsPage();
		operationsPage->show();
	}
}

DisplayTextPage::~DisplayTextPage()
{
	delete ui;
}
