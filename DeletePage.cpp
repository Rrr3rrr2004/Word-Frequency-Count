#include "MainWindow.h"

DeletePage::DeletePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DeletePageClass())
{
	ui->setupUi(this);
	QPixmap deleteLogo("./icons/delete.png");
	ui->display->setPlainText(GlobalFunctions::QParagraph);
	ui->deleteLogo->setPixmap(deleteLogo.scaled(50, 50, Qt::KeepAspectRatio));
	connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteText()));
	connect(ui->delete_allButton, SIGNAL(clicked()), this, SLOT(deleteAllText()));
	connect(ui->back, SIGNAL(clicked()), this, SLOT(moveToOperations()));
	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
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
	GlobalFunctions::writeToFile();
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

//Delete functions
void DeletePage::deleteText()
{
	bool flag = 0;
	GlobalFunctions::deleteFromText(ui->delText->text(),flag);
	if (!flag)
	{
		QMessageBox::information(this, "Warning!!", ui->delText->text() + "\nIS NOT VALID IN YOUR TEXT!!\nPlease, Enter another Sentance.");
	}
	else
	{
		QMessageBox::information(this, "Congratulation", "The Sentance Is Deleted.");
	}
}

void DeletePage::deleteAllText()
{
	GlobalFunctions::QParagraph.clear();
	QMessageBox::information(this, "Congraturaltion", "Your Text is Deleted Successfully");
}


DeletePage::~DeletePage()
{
	delete ui;
}