#include "SearchPage.h"
#include "MainWindow.h"
#include <QPixmap> 
#include <QMessageBox>

SearchPage::SearchPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SearchPageClass())
{
	ui->setupUi(this);
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

void SearchPage::searchWordFrequency(const QString& word, const QMap<QString, int>& wordFreqMap) {
	auto it = wordFreqMap.find(word);
	if (it != wordFreqMap.end()) {
		qDebug() << "Frequency of '" << word << "': " << it.value() << "\n";
	}
	else {
		qDebug() << "Word '" << word << "' not found in the paragraph.\n";
	}
}

SearchPage::~SearchPage()
{
	delete ui;
}
