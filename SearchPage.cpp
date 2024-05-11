#include "MainWindow.h"

SearchPage::SearchPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SearchPageClass())
{
	ui->setupUi(this);

	hisModel = new QStringListModel(this);
	comp = new QCompleter(hisModel, this);
	comp->setCaseSensitivity(Qt::CaseInsensitive);
	comp->setCompletionMode(QCompleter::PopupCompletion);

	ui->searchLine->setCompleter(comp);

	connect(ui->searchLine, SIGNAL(textChanged(QString)), this, SLOT(autoCompletion()));
	connect(ui->searchLine, SIGNAL(returnPressed()), this, SLOT(autoCorrection()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
}

void SearchPage::moveToOperations()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to return to the operations menu?", QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::Yes)
	{
		hide();
		OperationsPage* operationsPage = new OperationsPage();
		operationsPage->show();
	}
}

void SearchPage::moveToFinal()
{
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

void SearchPage::autoCompletion()
{
	GlobalFunctions::autoComplete(ui->searchLine->text(), hisModel, comp);
}

void SearchPage::autoCorrection()
{
	//QString text = ui->searchLine->text();
	string word = GlobalFunctions::autoCorrect(ui->searchLine->text().toStdString());
	//ui->searchLine->clear();
	ui->searchLine->setText(QString::fromStdString(word));
	int freq = GlobalFunctions::localFrequencies[word];
	ui->wordFreqLocal->setPlainText(QString::number(freq));
	freq = GlobalFunctions::globalFrequencies[word];
	ui->wordFreqGlobal->setPlainText(QString::number(freq));
}

SearchPage::~SearchPage()
{
	delete ui;
}
