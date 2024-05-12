#pragma once
#include <QMainWindow>
#include "ui_OperationsPage.h"
//#include "MainWindow.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class OperationsPageClass; };
QT_END_NAMESPACE

class DisplayTextPage;
class UpdatePage;
class DeletePage;
class SortAsc;
class SortDesc;
class DisplayFrequency;
class DisplayRank;
class SearchPage;

class OperationsPage : public QMainWindow
{
	Q_OBJECT

public:
	OperationsPage(QWidget* parent = nullptr);


	//vector<string> stringToVector(const string& text) const;

	//unordered_map<string, int> countWordFrequency();

	~OperationsPage();
private slots:
	void moveToDisplayText();
	void moveToUpdate();
	void moveToDelete();
	void moveToAsc();
	void moveToDesc();
	void moveToDisplayFreq();
	void moveToDisplayRank();
	void moveToSearch();
	void quitProgram();

private:
	DisplayTextPage* displayPage;
	UpdatePage* updatePage;
	DeletePage* deletePage;
	SortAsc* sortAcsPage;
	SortDesc* sortDescPage;
	DisplayFrequency* displayFreqPage;
	DisplayRank* displayRankPage;
	SearchPage* searchPage;

	//unordered_map<string, int> wordFrequency;


	Ui::OperationsPageClass* ui;
};