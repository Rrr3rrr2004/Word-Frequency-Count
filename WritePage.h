#pragma once
#include <QMainWindow>
#include "ui_WritePage.h"
#include <QFileDialog>
#include <QFile>

#include "MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WritePageClass; };
QT_END_NAMESPACE

class WritePage : public QMainWindow
{
	Q_OBJECT

public:
	WritePage(QWidget *parent = nullptr);
	~WritePage();

private slots:
	void writeToFile();
	void saveTextToFile();
	void moveToOperations();
	void back();

private:
	OperationsPage *operationsPage;
	HomePage* homePage;

	Ui::WritePageClass *ui;
};
