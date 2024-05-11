#pragma once
#include <QMainWindow>
#include "ui_DisplayRank.h"
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayRankClass; };
QT_END_NAMESPACE

class DisplayRank : public QMainWindow
{
	Q_OBJECT

public:
	DisplayRank(QWidget* parent = nullptr);
	~DisplayRank();

private slots:
	void moveToOperations();
	void moveToFinal();
	std::map<std::string, int> populateWordRanksTable();
	//multimap<int, std::string> populateWordRanksTable();

private:
	Ui::DisplayRankClass* ui;
};