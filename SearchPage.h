#pragma once
#include <QMainWindow>
#include "ui_SearchPage.h"

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
	void autoCorrection();
	QString getLastWord(const QString& text);
	//void searchWordFrequency(string, map<QString, int>);
private:
	Ui::SearchPageClass *ui;
};
