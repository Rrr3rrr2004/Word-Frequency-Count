#pragma once

#include <QMainWindow>
#include "ui_HomePage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomePageClass; };
QT_END_NAMESPACE

class MainWindow;
class WritePage;
//class OperationsPage;

class HomePage : public QMainWindow
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();

private slots:
	void moveToWrite();
	//void moveToUpload();
	//void moveToOperations();
	void quitProgram();
	void back();

private:
	MainWindow* mainWindow;
	WritePage* writePage;
	//OperationsPage* operationsPage;
	Ui::HomePageClass *ui;
};
