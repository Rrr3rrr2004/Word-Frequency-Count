#pragma once

#include <QMainWindow>
#include "ui_OperationsPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OperationsPageClass; };
QT_END_NAMESPACE

class OperationsPage : public QMainWindow
{
	Q_OBJECT

public:
	OperationsPage(QWidget *parent = nullptr);
	~OperationsPage();

private:
	Ui::OperationsPageClass *ui;
};
