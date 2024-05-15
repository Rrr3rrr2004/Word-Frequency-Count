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
	//vector<pair<string, int>> SortAsc::sortWordAsc(unordered_map<string, int>& paragraph);

	Ui::SortAscClass *ui;
};
