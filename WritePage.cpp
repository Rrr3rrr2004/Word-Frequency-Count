#include "WritePage.h"
using namespace std;

WritePage::WritePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::WritePageClass())
{
	ui->setupUi(this);
    connect(ui->saveFile, SIGNAL(clicked()), this, SLOT(saveTextToFile()));
}

void WritePage::saveTextToFile()
{
    //store the writtenParagraph in string after convert it
    //The text without editing
    QString QParagraph = ui->writeText->toPlainText();

    //editing the text
    QString QParagraphEdited = ui->writeText->toPlainText();
    QParagraphEdited.replace("\n", " ");
    QParagraphEdited = QParagraphEdited.toLower();

    //string text after editing
    string paragraph = QParagraphEdited.toStdString();

    //Open a file dialog to specify the file path
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt)"));

    if (!filePath.isEmpty())
    {
        writeToFile(filePath);
    }
}

void WritePage :: writeToFile(QString filePath)
{

    QFile file(filePath);
    // Open the file in write mode
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Create a QTextStream to write to the file
        QTextStream out(&file);
        // Write the data to the file
        out << ui->writeText->toPlainText();
        // Close the file
        file.close();
    }
}

WritePage::~WritePage()
{
	delete ui;
}
