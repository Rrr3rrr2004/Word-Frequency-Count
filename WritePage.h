#pragma once

#include <QMainWindow>
#include "ui_WritePage.h"
#include <QFileDialog>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class WritePageClass; };
QT_END_NAMESPACE

class OperationsPage;
class HomePage;

class WritePage : public QMainWindow
{
	Q_OBJECT

public:
	WritePage(QWidget *parent = nullptr);
	~WritePage();

private slots:
	void writeToFile(QString filePath);
	void saveTextToFile();
	void moveToOperations();
	void back();

private:
	OperationsPage *operationsPage;
	HomePage* homePage;
	Ui::WritePageClass *ui;
};
