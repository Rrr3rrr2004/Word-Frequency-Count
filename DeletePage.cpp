#include "MainWindow.h"
#include <Qset>
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
	GlobalFunctions::writeToFile();
	GlobalFunctions::allTexts.clear();
	GlobalFunctions::readAllTexts();
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

void DeletePage::autoCompletion()
{
	//delCompletion = ui->delText->text();
	//QString lastWord = GlobalFunctions::getLastWord(delCompletion);
	//GlobalFunctions::autoComplete(lastWord, hisModel, comp);
	////delCorrection += lastWord + " ";
	//ui->delText->clear();
	//ui->delText->setText(delCompletion);
	//delString += wordCorrection + " ";
	GlobalFunctions::autoComplete(ui->delText->text(), hisModel, comp);
}


//void DeletePage::on_plainTextEdit_textChanged()
//{
//	QString paragraphText = ui->delText->toPlainText();
//	QString p = GlobalFunctions::QParagraph.toLower();
//
//	// Define a regular expression pattern to match punctuation marks
//	QRegularExpression pattern("\\b|\\W");
//	QStringList history = p.split(pattern, Qt::SkipEmptyParts);
//	set<string> data;
//	for (QString word : history) {
//		data.insert(word.toStdString());
//	}
//	
//	// from plainText
//	QStringList wordsList = paragraphText.split(pattern, Qt::SkipEmptyParts);
//
//	set<string> filteredList;
//	QString x;
//	for (auto word : wordsList)
//	{
//		filteredList = findWordsStartingWith(word.toStdString(), data);
//		QStringList list;
//		for (string x : filteredList) {
//			list.append(QString::fromStdString(x));
//		}
//		hisModel = new QStringListModel(this);
//		hisModel->setStringList(list);
//		//ui->listView->setModel(hisModel);
//	}
//}

//std::set<std::string> DeletePage::findWordsStartingWith(const std::string& subword, const std::set<string>& text) {
//	std::set<std::string> wordsStartingWithSubword;
//
//	// Iterate through each word in the text
//	//std::string word;
//	for (string word: text) {
//		// Check if the word starts with the subword
//		if (word.substr(0, subword.size()) == subword) {
//			wordsStartingWithSubword.insert(word);
//		}
//	}
//
//	// Check the last word in case it's not followed by non-alphanumeric characters
//	//if (!word.empty() && word.substr(0, subword.size()) == subword) {
//		//wordsStartingWithSubword.insert(word);
//	//}
//
//	return wordsStartingWithSubword;
//}

/*void DeletePage::on_plainTextEdit_textChanged()
{
	set<string>data;
	set<string> filteredList;
	AutoC x;
			delText
	QString paragraphText = ui->plainTextEdit->toPlainText();
			QParagraph
	QString allParagraph = Files::readAllParagraphs();
	
	QStringList allParagraphList = paragraph.SplitParagrah(allParagraph);

	for (QString word : allParagraphList) {
		data.insert(word.toStdString());
	}
	QStringList fa = paragraph.SplitParagrah(paragraphText);

	for (auto word : fa)
	{
		x.autoComplete(word.toStdString(), filteredList, data);
		QStringList list;
		for (string x : filteredList) {
			list.append(QString::fromStdString(x));
		}
		modelplan = new QStringListModel(this);
		modelplan->setStringList(list);
		ui->listView_2->setModel(modelplan);
	}
}*/

void DeletePage::delAutoCorrection()
{
	GlobalFunctions::autoCorrection(ui->delText, delCorrection);
}

DeletePage::~DeletePage()
{
	delete ui;
}