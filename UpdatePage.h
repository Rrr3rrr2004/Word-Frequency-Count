#pragma once
#include <QMainWindow>
#include "ui_UpdatePage.h"
#include <QStringListModel>
#include <QCompleter>

QT_BEGIN_NAMESPACE
namespace Ui { class UpdatePageClass; };
QT_END_NAMESPACE

class OperationsPage;
class FinalPage;

class UpdatePage : public QMainWindow
{
	Q_OBJECT

public:
	UpdatePage(QWidget *parent = nullptr);
	~UpdatePage();

private slots:
	void moveToOperations();
	void moveToFinal();
	void autoComplete();
	void updateText();


private:
	QCompleter* completer;
	QStringListModel* historyModel;
	Ui::UpdatePageClass *ui;
};
