#include "SearchPage.h"
#include "MainWindow.h"
#include <QPixmap> 
#include <QMessageBox>

SearchPage::SearchPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SearchPageClass())
{
	ui->setupUi(this);
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
}

void SearchPage::moveToOperations()
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

void SearchPage::moveToFinal()
{
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

SearchPage::~SearchPage()
{
	delete ui;
}
