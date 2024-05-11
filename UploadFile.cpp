#include "MainWindow.h"

UploadFile::UploadFile(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::UploadFileClass())
{
	ui->setupUi(this);
	QPixmap logo("./icons/upload.png");
	ui->logo->setPixmap(logo.scaled(50, 50, Qt::KeepAspectRatio));
	connect(ui->uploadButton, SIGNAL(clicked()), this, SLOT(upload()));
	connect(ui->nextToOp, SIGNAL(clicked()), this, SLOT(moveToOperations()));
	connect(ui->backToHome, SIGNAL(clicked()), this, SLOT(back()));
}

void UploadFile::upload()
{
	GlobalFunctions::filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Text Files (*.txt)"));

	if (!GlobalFunctions::filePath.isEmpty())
	{
		QMessageBox::information(this, "Congratulation", "Your File Uploaded Successfully");
		GlobalFunctions::readFile(GlobalFunctions::filePath, GlobalFunctions::QParagraph);
	}
}

void UploadFile::moveToOperations()
{
	if (GlobalFunctions::filePath.isEmpty())
	{
		QMessageBox::warning(this, "Warning", "No File provided!!");
	}
	else
	{ 
		hide();
		OperationsPage* operationsPage = new OperationsPage();
		operationsPage->show();
	}
}

void UploadFile::back()
{
	hide();
	HomePage* homePage = new HomePage();
	homePage->show();
}

UploadFile::~UploadFile()
{
	delete ui;
}