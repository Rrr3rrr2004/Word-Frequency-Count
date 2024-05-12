#include "MainWindow.h"

DisplayRank::DisplayRank(QWidget* parent): QMainWindow(parent), ui(new Ui::DisplayRankClass())
{
    ui->setupUi(this);
    connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
    
    vector<pair<string, int>> rankedVector = populateWordRanksTable();

    ui->tableWidget->setRowCount(rankedVector.size());

    // Populate table
    int row = 0;
    for (auto pair : rankedVector)
    {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pair.first)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(pair.second)));
        ++row;
    }
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

vector<pair<string, int>> DisplayRank::populateWordRanksTable()
{
    multimap<int, string, greater<int>> sortedMap = SortDesc::sortWordsDesc();

    int rank = 0;
    int prevFrequency = -1;
    vector<pair<string, int>> ranks;

    for (auto pair : sortedMap)
    {
        int frequency = pair.first;
        string word = pair.second;

        if (frequency != prevFrequency)
        {
            rank++;
        }

        ranks.push_back(make_pair(word, rank));
        prevFrequency = frequency;
    }
    return ranks;
}

DisplayRank::~DisplayRank()
{
    delete ui;
}