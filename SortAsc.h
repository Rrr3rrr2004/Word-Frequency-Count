#pragma once

#include <QMainWindow>
#include "ui_SortAsc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SortAscClass; };
QT_END_NAMESPACE

class SortAsc : public QMainWindow
{
	Q_OBJECT

public:
	SortAsc(QWidget *parent = nullptr);
	~SortAsc();

private:
	Ui::SortAscClass *ui;
};
