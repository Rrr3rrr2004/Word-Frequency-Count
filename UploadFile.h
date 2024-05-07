#pragma once

#include <QMainWindow>
#include "ui_UploadFile.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class UploadFileClass; };
QT_END_NAMESPACE



class UploadFile : public QMainWindow
{
	Q_OBJECT

public:
	UploadFile(QWidget *parent = nullptr);
	~UploadFile();

private slots:
	void upload();
	void readFile(QString filePath);
	/*void next();
	void back();*/

private:
	//GlobalFunctions global;
	Ui::UploadFileClass *ui;
};
