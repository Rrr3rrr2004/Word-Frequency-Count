#include "MainWindow.h"

SortAsc::SortAsc(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SortAscClass())
{
	ui->setupUi(this);

	connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

	multimap<int, string> sortedMap = sortWordsAsc();
	ui->tableAsc->setRowCount(sortedMap.size());

	int row = 0;
	for (auto pair : sortedMap)
	{
		ui->tableAsc->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pair.second)));
		ui->tableAsc->setItem(row, 1, new QTableWidgetItem(QString::number(pair.first)));
		++row;
	}
}

void SortAsc::moveToOperations()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to return to the operations menu?", QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::Yes)
	{
		hide();
		OperationsPage* operationsPage = new OperationsPage();
		operationsPage->show();
	}
}

void SortAsc::moveToFinal()
{
	hide();
	FinalPage* finalPage = new FinalPage();
	finalPage->show();
}

std::multimap<int, std::string> SortAsc::sortWordsAsc()
{
	multimap<int, string> sortedMap;
	for (auto i : GlobalFunctions::localFrequencies)
	{
		sortedMap.insert({ i.second, i.first });
	}
	return sortedMap;
}

//another way to sortAsc

//vector<pair<string, int>> SortAsc::sortWordAsc(unordered_map<string, int>& paragraph)
//{
//	vector<pair<string, int>> vec(paragraph.begin(), paragraph.end());
//
//	bool swapped;
//	do
//	{
//		swapped = false;
//		for (int i = 0; i < vec.size() - 1; ++i)
//		{
//			if (vec[i].second > vec[i + 1].second)
//			{
//				swap(vec[i], vec[i + 1]);
//				swapped = true;
//			}
//		}
//	} while (swapped);
//
//	return vec;
//}

SortAsc::~SortAsc()
{
	delete ui;
}