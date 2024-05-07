#pragma once

#include <QMainWindow>
#include "ui_OperationsPage.h"

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
	OperationsPage(QWidget *parent = nullptr);
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

private:
	DisplayTextPage* displayPage;
	UpdatePage* updatePage;
	DeletePage* deletePage;
	SortAsc* sortAcsPage;
	SortDesc* sortDescPage;
	DisplayFrequency* displayFreqPage;
	DisplayRank* displayRankPage;
	SearchPage* searchPage;
	Ui::OperationsPageClass *ui;
};
