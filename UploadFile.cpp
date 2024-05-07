#include "UploadFile.h"
#include "MainWindow.h"


#include <QPixmap> 
#include <QMessageBox>

//#include "GlobalFunctions.h"

using namespace std;

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
	QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Text Files (*.txt)"));

	if (!filePath.isEmpty())
	{
		QMessageBox::information(this, "Congratulation", "Your File Uploaded Successfully");
		readFile(filePath);
	}
}

void UploadFile::readFile(QString filePath)
{
	QFile file(filePath);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);

		QString QParagraph = in.readAll();
		// store the Paragraph that in the file in paragraph after convert it to string
		QString fileContentEdited = QParagraph;
		fileContentEdited.replace("\n", " ");
		fileContentEdited = fileContentEdited.toLower();
		string paragraph = fileContentEdited.toStdString();

		file.close();
	}

}

void UploadFile::moveToOperations()
{
	hide();
	operationsPage = new OperationsPage();
	operationsPage->show();
}

void UploadFile::back()
{
	hide();
	homePage = new HomePage();
	homePage->show();
}

UploadFile::~UploadFile()
{
	delete ui;
}
