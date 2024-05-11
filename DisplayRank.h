#pragma once
#include <QMainWindow>
#include "ui_DisplayRank.h"
#include <map>
using namespace std;
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
	vector<pair<string, int>> populateWordRanksTable();

private:
	Ui::DisplayRankClass* ui;
};