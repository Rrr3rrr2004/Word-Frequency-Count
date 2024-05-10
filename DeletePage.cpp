#include "DeletePage.h"
#include "MainWindow.h"
#include <QPixmap> 
#include <QMessageBox>

DeletePage::DeletePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DeletePageClass())
{
	ui->setupUi(this);
	QPixmap deleteLogo("./icons/delete.png");
	displayPara();
	ui->deleteLogo->setPixmap(deleteLogo.scaled(50, 50, Qt::KeepAspectRatio));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	connect(ui->next, SIGNAL(triggered()), this, SLOT(moveToFinal()));
}

void DeletePage::moveToOperations()
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

void DeletePage::moveToFinal()
{
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

void DeletePage::displayPara()
{
	ui->display->setPlainText(GlobalFunctions::QParagraph);
}

DeletePage::~DeletePage()
{
	delete ui;
}
