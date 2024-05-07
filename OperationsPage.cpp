#pragma once
#include "MainWindow.h"
//#include "OperationsPage.h"
//#include "MainWindow.h"

//#include <QPixmap> 
//#include <QMessageBox>

OperationsPage::OperationsPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::OperationsPageClass())
{
	GlobalFunctions::countWordFrequency();

	ui->setupUi(this);
	QPixmap operation("./icons/operation.png");
	ui->operation->setPixmap(operation.scaled(50, 50, Qt::KeepAspectRatio));
	connect(ui->displayPara, SIGNAL(clicked()), this, SLOT(moveToDisplayText()));
	connect(ui->update, SIGNAL(clicked()), this, SLOT(moveToUpdate()));
	connect(ui->delete_2, SIGNAL(clicked()), this, SLOT(moveToDelete()));
	connect(ui->sortAsc, SIGNAL(clicked()), this, SLOT(moveToAsc()));
	connect(ui->sortDesc, SIGNAL(clicked()), this, SLOT(moveToDesc()));
	connect(ui->displayFreq, SIGNAL(clicked()), this, SLOT(moveToDisplayFreq()));
	connect(ui->diplayRank, SIGNAL(clicked()), this, SLOT(moveToDisplayRank()));
	connect(ui->search, SIGNAL(clicked()), this, SLOT(moveToSearch()));
}

void OperationsPage::moveToDisplayText() {
	hide();
	displayPage = new DisplayTextPage();
	displayPage->show();
}

void OperationsPage::moveToUpdate()
{
	hide();
	updatePage = new UpdatePage();
	updatePage->show();
}

void OperationsPage::moveToDelete() 
{
	hide();
	deletePage = new DeletePage();
	deletePage->show();
}

void OperationsPage::moveToAsc()
{
	hide();
	sortAcsPage = new SortAsc();
	sortAcsPage->show();
}

void OperationsPage::moveToDesc()
{
	hide();
	sortDescPage = new SortDesc();
	sortDescPage->show();
}

void OperationsPage::moveToDisplayFreq()
{
	//wordFrequency = countWordFrequency();
	hide();
	displayFreqPage = new DisplayFrequency();
	displayFreqPage->show();
}

void OperationsPage::moveToDisplayRank()
{
	hide();
	displayRankPage = new DisplayRank();
	displayRankPage->show();
}

void OperationsPage::moveToSearch()
{
	hide();
	searchPage = new SearchPage();
	searchPage->show();
}

//vector<string> OperationsPage::stringToVector(const string &text) const
//{
//	vector<string> words;
//	string word;
//	bool inWord = false;
//	for (char ch : text)
//	{
//		// Check if the character is a space
//		if (ch == ' ')
//		{
//			// If we are already in a word, add it to the vector
//			if (inWord)
//			{
//				words.push_back(word);
//				word.clear();
//				inWord = false;
//			}
//		}
//		else
//		{
//			// If not a space , add the character to the current word
//			word += ch; //basmala
//			inWord = true;
//		}
//	}
//
//	// Add the last word if it exists
//	if (!word.empty())
//	{
//		words.push_back(word);
//	}
//
//	return words;
//}

//unordered_map<string, int> OperationsPage::countWordFrequency()
//{
//	unordered_map<string, int> myCounter;
//	vector<string> words;
//	string text;
//	bool inWord = false;
//	//string word;
//
//	for (char ch : MainWindow::paragraph)
//	{
//		// ignore the punctuation marks from the paragraph
//		if (!ispunct(ch))
//		{
//			text += ch;
//		}
//	}
//
//	// convert the text to vector of string
//	words = stringToVector(text);
//
//	// count the frequency of each word
//	for (int i = 0; i < words.size(); i++)
//	{
//		myCounter[words[i]]++;
//	}
//	return myCounter;
//}

OperationsPage::~OperationsPage()
{
	delete ui;
}