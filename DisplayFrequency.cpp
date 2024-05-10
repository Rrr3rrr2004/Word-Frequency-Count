#include "MainWindow.h"

DisplayFrequency::DisplayFrequency(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DisplayFrequencyClass())
{
	ui->setupUi(this);
    ui->tableFreq->setRowCount(GlobalFunctions::localFrequencies.size());
    connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));

	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

    // Populate table
    int row = 0;
    for (auto pair : GlobalFunctions::localFrequencies)
    {
        ui->tableFreq->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pair.first)));
        ui->tableFreq->setItem(row, 1, new QTableWidgetItem(QString::number(pair.second)));
        for (auto pair2 : GlobalFunctions::globalFrequencies)
        {
            if (pair.first == pair2.first)
            {
                ui->tableFreq->setItem(row, 2, new QTableWidgetItem(QString::number(pair2.second)));
            }
        }
        ++row;
    }
}

void DisplayFrequency::moveToFinal()
{
    hide();
    FinalPage* finalPage = new FinalPage();
    finalPage->show();
}

DisplayFrequency::~DisplayFrequency()
{
	delete ui;
}
