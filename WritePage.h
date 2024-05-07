#pragma once

#include <QMainWindow>
#include "ui_WritePage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WritePageClass; };
QT_END_NAMESPACE

class WritePage : public QMainWindow
{
	Q_OBJECT

public:
	WritePage(QWidget *parent = nullptr);
	~WritePage();

private:
	Ui::WritePageClass *ui;
};
