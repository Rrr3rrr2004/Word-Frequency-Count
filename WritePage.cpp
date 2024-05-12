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
    if (ui->writeText->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "No text provided!!");
    }

    else
    {
        GlobalFunctions::QParagraph = ui->writeText->toPlainText();
        hide();
        operationsPage = new OperationsPage();
        operationsPage->show();
    }
}

void WritePage::saveTextToFile()
{
    GlobalFunctions::QParagraph = ui->writeText->toPlainText();

    GlobalFunctions::filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt)"));

    if (!GlobalFunctions::filePath.isEmpty())
    {
        GlobalFunctions::writeToFile();
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
