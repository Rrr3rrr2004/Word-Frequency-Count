#include "MainWindow.h"
#include <QPixmap> 
#include <QMessageBox>
#include "DisplayRank.h"

DisplayRank::DisplayRank(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DisplayRankClass())
{
	ui->setupUi(this);
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));

}

void DisplayRank::moveToOperations()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to discard your changes?", QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::Yes)
	{
		hide();
		OperationsPage* operationsPage = new OperationsPage();
		operationsPage->show();
	}
}

void DisplayRank::moveToFinal()
{
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

DisplayRank::~DisplayRank()
{
	delete ui;
}
