#pragma once
#include <QMainWindow>
#include "ui_SortAsc.h"
#include <map>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class SortAscClass; };
QT_END_NAMESPACE

class SortAsc : public QMainWindow
{
	Q_OBJECT

public:
	SortAsc(QWidget *parent = nullptr);
	~SortAsc();

private slots:
	void moveToOperations();
	void moveToFinal();

private:
	std::multimap<int, std::string> sortWordsAsc();
	//multimap<int, string> sortedMap;
	Ui::SortAscClass *ui;
};
