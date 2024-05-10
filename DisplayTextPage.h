#pragma once

#include <QMainWindow>
#include "ui_DisplayTextPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DisplayTextPageClass; };
QT_END_NAMESPACE
class OperationsPage;


class DisplayTextPage : public QMainWindow
{
	Q_OBJECT

public:
	DisplayTextPage(QWidget *parent = nullptr);
	~DisplayTextPage();

private slots:
	void displayPara();
	void moveToOperations1();
	void moveToFinal();

private:
	OperationsPage* operationsPage;
	Ui::DisplayTextPageClass *ui;
};
