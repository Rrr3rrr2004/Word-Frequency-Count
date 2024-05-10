#include "SortAsc.h"
#include "MainWindow.h"
#include <QPixmap> 
#include <QMessageBox>

SortAsc::SortAsc(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SortAscClass())
{
	ui->setupUi(this);
	connect(ui->next, SIGNAL(triggered()), this, SLOT(moveToFinal()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

}

void SortAsc::moveToOperations()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to return to the operations menu?", QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::Yes)
	{
		hide();
		OperationsPage* operationsPage = new OperationsPage();
		operationsPage->show();
	}
}

void SortAsc::moveToFinal()
{
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

SortAsc::~SortAsc()
{
	delete ui;
}
