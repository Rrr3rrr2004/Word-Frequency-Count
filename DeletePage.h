#pragma once
#include <QMainWindow>
#include "ui_DeletePage.h"
#include <QStringListModel>
#include <QCompleter>
QT_BEGIN_NAMESPACE
namespace Ui { class DeletePageClass; };
QT_END_NAMESPACE

class DeletePage : public QMainWindow
{
	Q_OBJECT

public:
	DeletePage(QWidget *parent = nullptr);
	~DeletePage();

private slots:
	void moveToOperations();
	void moveToFinal();
	void deleteText();
	void deleteAllText();
	void autoCompletion();


private:
	QCompleter* comp;
	QStringListModel* hisModel;
	
	Ui::DeletePageClass *ui;
};
