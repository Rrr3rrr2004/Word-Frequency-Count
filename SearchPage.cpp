#include "MainWindow.h"

SearchPage::SearchPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SearchPageClass())
{
	ui->setupUi(this);
	connect(ui->searchLine, SIGNAL(returnPressed()), this, SLOT(autoCorrection()));
	//connect(ui->searchLine, SIGNAL(textChanged()), this, SLOT(autoCorrection()));
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

//void SearchPage::searchWordFrequency( QString& word,  QMap<QString, int> wordFreqMap) {
//	auto it = wordFreqMap.find(word);
//	if (it != wordFreqMap.end()) {
//		qDebug() << "Frequency of '" << word << "': " << it.value() << "\n";
//	}
//	else {
//		qDebug() << "Word '" << word << "' not found in the paragraph.\n";
//	}
//}


QString SearchPage::getLastWord(const QString& text) {
	// Split the text into individual words
	QStringList words = text.split(QRegularExpression("\\b|\\W"), Qt::SkipEmptyParts);

	// Check if there are any words
	if (!words.isEmpty()) {
		// Return the last word
		return words.last();
	}
	else {
		// Return an empty string if there are no words
		return QString();
	}
}

void SearchPage::autoCorrection()
{
	QString text = ui->searchLine->text();
	string word = GlobalFunctions::autoCorrect(getLastWord(text).toStdString());
	//ui->searchLine->clear();
	ui->searchLine->setText(QString::fromStdString(word));
}

SearchPage::~SearchPage()
{
	delete ui;
}
