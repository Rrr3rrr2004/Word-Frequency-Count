#include "MainWindow.h"

SortAsc::SortAsc(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SortAscClass())
{
	ui->setupUi(this);
	//connect(ui->next, SIGNAL(triggered()), this, SLOT(moveToFinal()));
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

    ui->tableAsc->setRowCount(GlobalFunctions::localFrequencies.size());

    //connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
    //connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

    // Populate table
    int row = 0;
    for (auto pair : GlobalFunctions::localFrequencies)
    {
        ui->tableAsc->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pair.first)));
        ui->tableAsc->setItem(row, 1, new QTableWidgetItem(QString::number(pair.second)));
        ++row;
    }

}

SortAsc::~SortAsc()
{
	delete ui;
}
