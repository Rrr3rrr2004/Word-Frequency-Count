#include "MainWindow.h"

DisplayFrequency::DisplayFrequency(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DisplayFrequencyClass())
{
	ui->setupUi(this);
    ui->tableFreq->setRowCount(GlobalFunctions::localFrequencies.size());
    connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
    
    displayFreqTable();
}

void DisplayFrequency::displayFreqTable()
{
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

void DisplayFrequency::moveToOperations()
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