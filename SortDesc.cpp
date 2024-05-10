#include "SortDesc.h"
#include "MainWindow.h"
#include <QPixmap> 
#include <QMessageBox>


SortDesc::SortDesc(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SortDescClass())
{
	ui->setupUi(this);
	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));


}

void SortDesc::moveToOperations()
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

void SortDesc::moveToFinal()
{
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

SortDesc::~SortDesc()
{
	delete ui;
}
