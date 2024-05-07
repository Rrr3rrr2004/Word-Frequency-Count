#include "UploadFile.h"
using namespace std;

UploadFile::UploadFile(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::UploadFileClass())
{
	ui->setupUi(this);
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
UploadFile::~UploadFile()
{
	delete ui;
}
