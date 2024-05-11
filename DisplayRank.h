#pragma once

#include <QMainWindow>
#include "ui_DisplayRank.h"

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
	void populateWordRanksTable();

private:
	Ui::DisplayRankClass* ui;
};