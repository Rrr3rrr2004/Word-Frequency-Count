#include "MainWindow.h"

DisplayRank::DisplayRank(QWidget* parent): QMainWindow(parent), ui(new Ui::DisplayRankClass())
{
    ui->setupUi(this);
    connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
    //populateWordRanksTable();
    
    //multimap<int, std::string> rankedVector = populateWordRanksTable();
    std::map<std::string, int> rankedVector = populateWordRanksTable();

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

DisplayRank::~DisplayRank()
{
    delete ui;
}

std::map<std::string, int> DisplayRank::populateWordRanksTable()
{
    std::multimap<int, std::string, std::greater<int>> sortedMap = SortDesc::sortWordsDesc();

    //unordered_map<int, int> rankMap;  // Map to store rank for each frequency
    int rank = 1;

    std::map<std::string, int> r;
    for (auto pair : sortedMap) {
        //int frequency = pair.first;

        r[pair.second] = rank;
        rank++;
    }
    return r;
}


//std::multimap<int,std::string> DisplayRank::populateWordRanksTable()
//{
//    std::multimap<int, std::string> rankedWords;
// 
//    std::multimap<int, std::string, std::greater<int>> sortedMap = SortDesc::sortWordsDesc();
//    int rank = 0;
//    for (auto word: sortedMap)
//    {
//        int frequency = word.first;
//
//        if (rankedWords.end()->first!=frequency) {
//            rank++;
//        }
//        rankedWords.insert({ word.first, word.second });
//    }
//    return rankedWords;
//}

//void DisplayRank::displayWordRanks()
//{
//    // Displaying word ranks via QMessageBox
//    multimap<int, string, greater<int>> sortedMap = SortDesc::sortWordsDesc();
//    QString output = "Word ranks based on frequency:\n";
//    int rank = 1;
//    for (const auto& pair : sortedMap) {
//        output += QString::fromStdString(pair.second) + "\t" + QString::number(rank++) + "\n";
//    }
//    QMessageBox::information(this, "Word Ranks", output);
//}