#pragma once

#include <QMainWindow>
#include "ui_DeletePage.h"


QT_BEGIN_NAMESPACE
namespace Ui { class DeletePageClass; };
QT_END_NAMESPACE

class DeletePage : public QMainWindow
{
	Q_OBJECT

public:
	DeletePage(QWidget *parent = nullptr);
	~DeletePage();

private:
	
	Ui::DeletePageClass *ui;
};
