#include "MainWindow.h"

using namespace std;

WritePage::WritePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::WritePageClass())
{
	ui->setupUi(this);
    connect(ui->saveFile, SIGNAL(clicked()), this, SLOT(saveTextToFile()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToOperations()));
    connect(ui->back, SIGNAL(clicked()), this, SLOT(back()));
}

void WritePage::moveToOperations()
{
    QMessageBox::warning(this, "Warning", "No text provided");

    hide();
    operationsPage = new OperationsPage();
    operationsPage->show();
}

void WritePage::saveTextToFile()
{
    //store the writtenParagraph in string after convert it
    //The text without editing
    GlobalFunctions::QParagraph = ui->writeText->toPlainText();

    //editing the text
    //QString QParagraphEdited = ui->writeText->toPlainText();
    //QParagraphEdited.replace("\n", " ");
    //QParagraphEdited = QParagraphEdited.toLower();

    //string text after editing
    //GlobalFunctions::paragraph = QParagraphEdited.toStdString();

    //Open a file dialog to specify the file path
    GlobalFunctions::filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt)"));

    if (!GlobalFunctions::filePath.isEmpty())
    {
        GlobalFunctions::writeToFile();
    }
}

//void WritePage::writeToFile()
//{
//    QFile file(GlobalFunctions::filePath);
//    // Open the file in write mode
//    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
//    {
//        // Create a QTextStream to write to the file
//        QTextStream out(&file);
//        // Write the data to the file
//        out << GlobalFunctions::QParagraph;
//        // Close the file
//        file.close();
//    }
//}

void WritePage::back()
{
    hide();
    homePage = new HomePage();
    homePage->show();
}

WritePage::~WritePage()
{
	delete ui;
}
