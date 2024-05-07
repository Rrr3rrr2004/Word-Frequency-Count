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
    hide();
    operationsPage = new OperationsPage();
    operationsPage->show();
}

void WritePage::saveTextToFile()
{
    //store the writtenParagraph in string after convert it
    //The text without editing
    MainWindow::QParagraph = ui->writeText->toPlainText();

    //editing the text
    QString QParagraphEdited = ui->writeText->toPlainText();
    QParagraphEdited.replace("\n", " ");
    QParagraphEdited = QParagraphEdited.toLower();

    //string text after editing
    MainWindow::paragraph = QParagraphEdited.toStdString();

    //Open a file dialog to specify the file path
    MainWindow::filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt)"));

    if (!MainWindow::filePath.isEmpty())
    {
        writeToFile();
    }
}

void WritePage :: writeToFile()
{
    QFile file(MainWindow::filePath);
    // Open the file in write mode
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // Create a QTextStream to write to the file
        QTextStream out(&file);
        // Write the data to the file
        out << MainWindow::QParagraph;
        // Close the file
        file.close();
    }
}

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
