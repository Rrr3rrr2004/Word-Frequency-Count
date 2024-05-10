//#include "HomePage.h"
#include "MainWindow.h"

HomePage::HomePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::HomePageClass())
{
	ui->setupUi(this);
	QPixmap logo("./icons/search.png");
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

void HomePage::moveToUpload()
{
	hide();
	uploadFile = new UploadFile();
	uploadFile->show();
}

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
