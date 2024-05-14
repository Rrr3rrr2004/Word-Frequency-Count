#pragma once

#include <QMainWindow>
#include "ui_DisplayFrequency.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayFrequencyClass; };
QT_END_NAMESPACE

class DisplayFrequency : public QMainWindow
{
	Q_OBJECT

public:
	DisplayFrequency(QWidget *parent = nullptr);
	~DisplayFrequency();

private slots:
	void moveToOperations();
	void moveToFinal();
	void displayFreqTable();

private:

	Ui::DisplayFrequencyClass *ui;
};
