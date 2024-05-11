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
	void SearchPage::searchWordFrequency(const QString& word, const QMap<QString, int>& wordFreqMap)

private:
	Ui::SearchPageClass *ui;
};
