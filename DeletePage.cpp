#include "MainWindow.h"
#include <Qset>
#include "GlobalFunctions.h"

DeletePage::DeletePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DeletePageClass())
{
	//delCorrection.clear();
	delCorrection.clear();
	ui->setupUi(this);
	QPixmap deleteLogo("./icons/delete.png");
	ui->display->setPlainText(GlobalFunctions::QParagraph);
	ui->deleteLogo->setPixmap(deleteLogo.scaled(50, 50, Qt::KeepAspectRatio));

	hisModel = new QStringListModel(this);
	comp = new QCompleter(hisModel, this);
	comp->setCaseSensitivity(Qt::CaseInsensitive);
	comp->setCompletionMode(QCompleter::PopupCompletion);

	ui->delText->setCompleter(comp);

	connect(ui->delText, SIGNAL(textChanged(QString)), this, SLOT(autoCompletion()));
	connect(ui->delText, SIGNAL(returnPressed()), this, SLOT(delAutoCorrection()));

	connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteText()));
	connect(ui->delete_allButton, SIGNAL(clicked()), this, SLOT(deleteAllText()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
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
	GlobalFunctions::allTexts.clear();
	GlobalFunctions::writeToFile();
	GlobalFunctions::readAllTexts();
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}


//Delete functions
void DeletePage::deleteText()
{
	if (ui->delText->text().isEmpty())
	{
		QMessageBox::warning(this, "Warning!!","There is no text provided to delete!");
		return;
	}
	bool flag = 0;
	GlobalFunctions::deleteFromText(ui->delText->text(),flag);
	if (!flag)
	{
		QMessageBox::information(this, "Warning!!", ui->delText->text() + "\nIS NOT VALID IN YOUR TEXT!!\nPlease, Enter another Sentance.");
		return;
	}
	QMessageBox::information(this, "Congratulation", "The Sentance Is Deleted.");
	ui->display->setPlainText(GlobalFunctions::QParagraph);
}

void DeletePage::deleteAllText()
{
	GlobalFunctions::QParagraph.clear();
	QMessageBox::information(this, "Congraturaltion", "Your Text is Deleted Successfully");
	ui->display->setPlainText(GlobalFunctions::QParagraph);
}

void DeletePage::autoCompletion()
{
	GlobalFunctions::autoComplete(ui->delText->text(), hisModel, comp);
}

void DeletePage::delAutoCorrection()
{
	GlobalFunctions::autoCorrection(ui->delText, delCorrection);
}

DeletePage::~DeletePage()
{
	delete ui;
}