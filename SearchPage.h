#pragma once
#include <QMainWindow>
#include "ui_SearchPage.h"
#include <QStringListModel>
#include <QCompleter>

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
	//QString getLastWord(const QString& text);
	//void searchWordFrequency(string, map<QString, int>);
private:
	QCompleter* comp;
	QStringListModel* hisModel;

	Ui::SearchPageClass *ui;
};
