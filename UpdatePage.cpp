#include "MainWindow.h"


UpdatePage::UpdatePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::UpdatePageClass())
{
	ui->setupUi(this);
	QPixmap update("./icons/update.png");
	ui->update->setPixmap(update.scaled(50, 50, Qt::KeepAspectRatio));

	// Create the QStringListModel
	historyModel = new QStringListModel(this);

	// Create the QCompleter with the QStringListModel
	completer = new QCompleter(historyModel, this);
	completer->setCaseSensitivity(Qt::CaseInsensitive);
	completer->setCompletionMode(QCompleter::PopupCompletion);

	// Set the QCompleter to the QLineEdit widgets
	ui->oldLine->setCompleter(completer);
	ui->newLine->setCompleter(completer);

	connect(ui->oldLine, SIGNAL(textChanged(QString)), this, SLOT(autoComplete()));
	//connect(ui->newLine, SIGNAL(textChanged(QString)), this, SLOT(autoComplete()));

	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

	//// Create a QLineEdit widget
	//lineEdit = new QLineEdit(searchPage);
	//historyModel = new QStringListModel(searchPage);
	//// Create a QCompleter with the QStringListModel
	//completer = new QCompleter(historyModel, searchPage);
	//completer->setCaseSensitivity(Qt::CaseInsensitive); // Optional: Case insensitive completion
	//// Set the completer to provide suggestions as the user types
	//completer->setCompletionMode(QCompleter::PopupCompletion);
	//// Set the completer to the line edit widget
	//// Connect the returnPressed signal of the line edit to a slot to update the history
	//connect(lineEdit, &QLineEdit::textChanged, this, &MainWindow::autoComplete);

}

//code of all move to operations function
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
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

void UpdatePage::autoComplete()
{
	//QString p = GlobalFunctions::QParagraph.toLower();

	// Define a regular expression pattern to match punctuation marks
	//QRegularExpression pattern("\\b|\\W");
	//QStringList history = p.split(pattern, Qt::SkipEmptyParts);
	QStringList words = GlobalFunctions::QParagraph.toLower().split(" ", Qt::SkipEmptyParts);

	QStringList textLine= ui->oldLine->text().split(QRegularExpression("\\b|\\W"), Qt::SkipEmptyParts);
	QString lastWord = textLine.isEmpty() ? "" : textLine.last();
	//QStringList textLine = ui->oldLine->text().split(" ", Qt::SkipEmptyParts);
 
	// Split the entered text into individual words
	//QStringList words = GlobalFunctions::QParagraph.split(QRegularExpression("\\b|\\W"), Qt::SkipEmptyParts);

	// Use a set to remove duplicates
	QSet<QString> uniqueWords;

	for (const QString& word : words)
	{
		uniqueWords.insert(word);
	}

	QStringList filteredList;
	for (const QString& word : uniqueWords)
	{
		filteredList << word;
	}

	// Convert the set back to a QStringList

	// Set the QStringListModel with the filtered list
	historyModel->setStringList(filteredList);

	// Set the completion prefix and complete
	completer->setCompletionPrefix(lastWord);
	completer->complete();

	//// Add the entered text to the history
	////QString p = GlobalFunctions::QParagraph.toLower();

	//// Define a regular expression pattern to match punctuation marks
	//QRegularExpression pattern("\\b|\\W");
	//QStringList history = GlobalFunctions::QParagraph.split(pattern, Qt::SkipEmptyParts);

	//QSet<QString> uniqueWords;
	//QStringList filteredList;

	//for (const QString& word : history)
	//{
	//	uniqueWords.insert(word);
	//	filteredList << word;
	//}

	//for (const QString& word : uniqueWords)
	//{
	//	filteredList << word;
	//}
	//QStringListModel* historyModel = new QStringListModel(this);
	//historyModel->setStringList(filteredList);
	//completer = new QCompleter(historyModel, this);
	//completer->setCaseSensitivity(Qt::CaseInsensitive);
	//completer->setCompletionMode(QCompleter::PopupCompletion);

	////QString text = ui->oldLine->text();
	////Split the entered text into individual words
	////QStringList words = text.split(" ", Qt::SkipEmptyParts);

	////Take the last word for auto-completion
	////QString lastWord = words.isEmpty() ? "" : words.last();

	//completer->setCompletionPrefix(ui->oldLine->text());
	//completer->complete();
}

UpdatePage::~UpdatePage()
{
	delete ui;
}
