#pragma once

#include <QMainWindow>
#include "ui_UploadFile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UploadFileClass; };
QT_END_NAMESPACE

class OperationsPage;
class HomePage;

class UploadFile : public QMainWindow
{
	Q_OBJECT

public:
	UploadFile(QWidget *parent = nullptr);
	~UploadFile();

private slots:
	void upload();
	void readFile(QString filePath);
	void moveToOperations();
	void back();

private:
	//GlobalFunctions global;
	OperationsPage* operationsPage;
	HomePage* homePage;
	Ui::UploadFileClass *ui;
};
