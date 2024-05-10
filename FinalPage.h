#pragma once

#include <QMainWindow>
#include "ui_FinalPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FinalPageClass; };
QT_END_NAMESPACE

class FinalPage : public QMainWindow
{
	Q_OBJECT

public:
	FinalPage(QWidget *parent = nullptr);
	~FinalPage();

private slots:
	void moveToOperations();
	void quitProgram();
private:
	Ui::FinalPageClass *ui;
};
