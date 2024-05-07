#include "HomePage.h"
#include "MainWindow.h"
#include "WritePage.h"

#include <QPixmap> 
#include <QMessageBox>




HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::HomePageClass())
{
	ui->setupUi(this);
	QPixmap logo("D:/Design/atock/icons/search");
	ui->logo->setPixmap(logo.scaled(50, 50, Qt::KeepAspectRatio));
	connect(ui->write, SIGNAL(clicked()), this, SLOT(moveToWrite()));
	connect(ui->upload, SIGNAL(clicked()), this, SLOT(moveToUpload()));
	connect(ui->back, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui->close, SIGNAL(triggered()), this, SLOT(quitProgram()));
}

void HomePage::moveToWrite()
{
	hide();
	writePage = new WritePage();
	writePage->show();
}

//void HomePage::moveToUpload()
//{
//
//}

//void HomePage::moveToOperations()
//{
//	hide();
//	operationsPage = new OperationsPage();
//	operationsPage->show();
//}

void HomePage::back()
{
	hide();
	mainWindow = new MainWindow();
	mainWindow->show();
}

void HomePage::quitProgram()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to close the program?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		QApplication::quit();
	}
}

HomePage::~HomePage()
{
	delete ui;
}
