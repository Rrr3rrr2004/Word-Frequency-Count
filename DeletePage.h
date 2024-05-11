#pragma once
#include <QMainWindow>
#include "ui_DeletePage.h"
#include <QStringListModel>
#include <QCompleter>
#include <set>
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
	void autoCorrection();

private:
	QCompleter* comp;
	QStringListModel* hisModel;
	QString delCorrection;
	QString delCompletion;

	//void on_plainTextEdit_textChanged();
	//std::set<std::string> findWordsStartingWith(const std::string& subword, const std::set<std::string>& text);


	
	Ui::DeletePageClass *ui;
};
