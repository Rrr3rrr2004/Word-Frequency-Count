#include "MainWindow.h"
#include <QPixmap> 
#include <QMessageBox>
#include "DisplayRank.h"

DisplayRank::DisplayRank(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::DisplayRankClass())
{
    ui->setupUi(this);
    connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
    populateWordRanksTable();
}

void DisplayRank::moveToOperations()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
        "Do you want to return to the operations menu?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        hide();
        OperationsPage* operationsPage = new OperationsPage();
        operationsPage->show();
    }
}

void DisplayRank::moveToFinal()
{
    hide();
    FinalPage* finalPage = new FinalPage();
    finalPage->show();
}

DisplayRank::~DisplayRank()
{
    delete ui;
}

void DisplayRank::populateWordRanksTable()
{
    multimap<int, string, greater<int>> sortedMap = SortDesc::sortWordsDesc();

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(sortedMap.size());

    unordered_map<int, int> rankMap;  
    int rank = 1;
    int row = 0;

    for (const auto& pair : sortedMap) {
        QTableWidgetItem* wordItem = new QTableWidgetItem(QString::fromStdString(pair.second));
        int frequency = pair.first;

        if (rankMap.find(frequency) == rankMap.end()) {
            rankMap[frequency] = rank++;
        }

        QTableWidgetItem* rankItem = new QTableWidgetItem(QString::number(rankMap[frequency]));

        ui->tableWidget->setItem(row, 0, wordItem);
        ui->tableWidget->setItem(row, 1, rankItem);

        ++row;
    }
}





