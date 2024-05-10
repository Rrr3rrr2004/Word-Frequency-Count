#include "FinalPage.h"
#include "MainWindow.h"


FinalPage::FinalPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::FinalPageClass())
{
	ui->setupUi(this);
	QPixmap logo("./icons/search.png");
	ui->logo->setPixmap(logo.scaled(75, 75, Qt::KeepAspectRatio));
	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToOperations()));
	connect(ui->quit, SIGNAL(clicked()), this, SLOT(quitProgram()));

}

void FinalPage::moveToOperations()
{
	hide();
	OperationsPage* operationsPage = new OperationsPage();
	operationsPage->show();
}

void FinalPage::quitProgram()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to close the program?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		QApplication::quit();
	}
}
FinalPage::~FinalPage()
{
	delete ui;
}
