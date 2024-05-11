#include "MainWindow.h"

SortDesc::SortDesc(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::SortDescClass())
{
    ui->setupUi(this);

    connect(ui->next, SIGNAL(triggered()), this, SLOT(moveToFinal()));
    connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

    std::multimap<int, std::string, std::greater<int>> sortedMap = sortWordsDesc();
    ui->sortDescTable->setRowCount(sortedMap.size());

    // Populate table
    int row = 0;
    for (auto pair : sortedMap)
    {
        ui->sortDescTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pair.second)));
        ui->sortDescTable->setItem(row, 1, new QTableWidgetItem(QString::number(pair.first)));
        ++row;
    }
}

void SortDesc::moveToOperations()
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

void SortDesc::moveToFinal()
{
    hide();
    FinalPage* finalPage = new FinalPage();
    finalPage->show();
}

std::multimap<int, std::string, std::greater<int>> SortDesc::sortWordsDesc() 
{
    std::multimap<int, std::string, std::greater<int>> sortedMap;
    for (auto i : GlobalFunctions::localFrequencies)
    {
        sortedMap.insert({ i.second, i.first });
    }
    return sortedMap;
}

SortDesc::~SortDesc()
{
    delete ui;
}
