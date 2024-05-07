#pragma once

#include <QMainWindow>
#include "ui_SortDesc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SortDescClass; };
QT_END_NAMESPACE

class SortDesc : public QMainWindow
{
	Q_OBJECT

public:
	SortDesc(QWidget *parent = nullptr);
	~SortDesc();

private:
	Ui::SortDescClass *ui;
};