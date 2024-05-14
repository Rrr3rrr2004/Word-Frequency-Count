#pragma once
#include <QMainWindow>
#include "ui_SearchPage.h"
#include <QStringListModel>
#include <QCompleter>
#include <string>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class SearchPageClass; };
QT_END_NAMESPACE

class SearchPage : public QMainWindow
{
	Q_OBJECT

public:
	SearchPage(QWidget *parent = nullptr);
	~SearchPage();

private slots:
	void moveToOperations();
	void moveToFinal();
	void autoCompletion();
	void autoCorrection();
	void displayWord(string word);

private:
	QCompleter* comp;
	QStringListModel* hisModel;

	Ui::SearchPageClass *ui;
};
