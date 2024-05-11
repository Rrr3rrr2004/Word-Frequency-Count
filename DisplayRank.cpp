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
    int rank = 1;
    vector<pair<string, int>> r;
    for (auto pair : sortedMap) {
        if (!r.empty())
        {
            if (pair.first != r[r.size() - 1].second)
            {
                r.push_back(make_pair(pair.second, ++rank));
                continue;
            }
            else
            {
                r.push_back(make_pair(pair.second, rank));
            }
        }
        else
        {
            r.push_back(make_pair(pair.second, rank));
        }
    }
    return r;
}

DisplayRank::~DisplayRank()
{
    delete ui;
}