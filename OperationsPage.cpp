#pragma once
#include "MainWindow.h"

OperationsPage::OperationsPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::OperationsPageClass())
{
	GlobalFunctions::allTexts = "";
	GlobalFunctions::readAllTexts();
	GlobalFunctions::localFrequencies = GlobalFunctions::countWordFrequency(GlobalFunctions::QParagraph);
	GlobalFunctions::globalFrequencies = GlobalFunctions::countWordFrequency(GlobalFunctions::allTexts);

	ui->setupUi(this);
	QPixmap operation("./icons/operation.png");
	ui->operation->setPixmap(operation.scaled(50, 50, Qt::KeepAspectRatio));
	connect(ui->displayPara, SIGNAL(clicked()), this, SLOT(moveToDisplayText()));
	connect(ui->displayFreq, SIGNAL(clicked()), this, SLOT(moveToDisplayFreq()));

	connect(ui->update, SIGNAL(clicked()), this, SLOT(moveToUpdate()));
	connect(ui->delete_2, SIGNAL(clicked()), this, SLOT(moveToDelete()));
	connect(ui->sortAsc, SIGNAL(clicked()), this, SLOT(moveToAsc()));
	connect(ui->sortDesc, SIGNAL(clicked()), this, SLOT(moveToDesc()));
	connect(ui->diplayRank, SIGNAL(clicked()), this, SLOT(moveToDisplayRank()));
	connect(ui->search, SIGNAL(clicked()), this, SLOT(moveToSearch()));
	connect(ui->close, SIGNAL(triggered()), this, SLOT(quitProgram()));
}

void OperationsPage::moveToDisplayText() {
	hide();
	displayPage = new DisplayTextPage();
	displayPage->show();
}

void OperationsPage::moveToUpdate()
{
	hide();
	updatePage = new UpdatePage();
	updatePage->show();
}

void OperationsPage::moveToDelete() 
{
	hide();
	deletePage = new DeletePage();
	deletePage->show();
}

void OperationsPage::moveToAsc()
{
	hide();
	sortAcsPage = new SortAsc();
	sortAcsPage->show();
}

void OperationsPage::moveToDesc()
{
	hide();
	sortDescPage = new SortDesc();
	sortDescPage->show();
}

void OperationsPage::moveToDisplayFreq()
{
	//wordFrequency = countWordFrequency();
	hide();
	displayFreqPage = new DisplayFrequency();
	displayFreqPage->show();
}

void OperationsPage::moveToDisplayRank()
{
	hide();
	displayRankPage = new DisplayRank();
	displayRankPage->show();
}

void OperationsPage::moveToSearch()
{
	hide();
	searchPage = new SearchPage();
	searchPage->show();
}

 void OperationsPage::quitProgram()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to close the program?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		QApplication::quit();
	}
}

OperationsPage::~OperationsPage()
{
	delete ui;
}