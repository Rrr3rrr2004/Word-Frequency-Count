#include "MainWindow.h"

UpdatePage::UpdatePage(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::UpdatePageClass())
{
	ui->setupUi(this);
	QPixmap update("./icons/update.png");
	ui->update->setPixmap(update.scaled(50, 50, Qt::KeepAspectRatio));

	ui->textEdit->setPlainText(GlobalFunctions::QParagraph);

	historyModel = new QStringListModel(this);
	completer = new QCompleter(historyModel, this);
	completer->setCaseSensitivity(Qt::CaseInsensitive);
	completer->setCompletionMode(QCompleter::PopupCompletion);

	ui->oldLine->setCompleter(completer);
	ui->newLine->setCompleter(completer);

	connect(ui->oldLine, SIGNAL(textChanged(QString)), this, SLOT(autoCompletion()));
	//connect(ui->newLine, SIGNAL(textChanged(QString)), this, SLOT(autoComplete()));

	connect(ui->oldLine, SIGNAL(returnPressed()), this, SLOT(oldAutoCorrection()));
	connect(ui->newLine, SIGNAL(returnPressed()), this, SLOT(newAutoCorrection()));


	connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(updateText()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
}

void UpdatePage::moveToOperations()
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

void UpdatePage::moveToFinal()
{
	GlobalFunctions::writeToFile();
	GlobalFunctions::writeToFile();
	GlobalFunctions::allTexts.clear();
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}


void UpdatePage::autoCompletion()
{
	GlobalFunctions::autoComplete(ui->oldLine->text(), historyModel, completer);
}

void UpdatePage::oldAutoCorrection()
{
	GlobalFunctions::autoCorrection(ui->oldLine,textCorrection);
}

void UpdatePage::newAutoCorrection()
{
	GlobalFunctions::autoCorrection(ui->newLine,textCorrection);
}

void UpdatePage::updateText()
{
	if (ui->oldLine->text().isEmpty()|| ui->newLine->text().isEmpty())
	{
		QMessageBox::warning(this, "Warning!!", "There is no text provided to update!");
		return;
	}
	bool flag = 0;
	int index = GlobalFunctions::deleteFromText(ui->oldLine->text(), flag);

	if (!flag)
	{
		QMessageBox::information(this, "Warning!!", ui->oldLine->text() + "\nIS NOT VALID IN YOUR TEXT!!\nPlease, Enter another Sentance.");
		return;
	}

	string sNewText = ui->newLine->text().toStdString();
	vector<string> newVector = GlobalFunctions::stringToVector(sNewText);

	QString paragraph = GlobalFunctions::QParagraph;
	vector<string> paraVector = GlobalFunctions::stringToVector(paragraph.replace("\n", " ").toLower().toStdString());

	for (int i = 0; i < newVector.size(); i++)
	{
		paraVector.insert(paraVector.begin() + index, newVector[i]);
		index++;
	}

	string finalPara = GlobalFunctions::vectorToString(paraVector);
	GlobalFunctions::QParagraph = QString::fromStdString(finalPara);
	QMessageBox::information(this, "Congratulation", "The Sentance Is Updated.");
}

UpdatePage::~UpdatePage()
{
	delete ui;
}