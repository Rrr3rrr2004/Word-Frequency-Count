#include "MainWindow.h"

SortDesc::SortDesc(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::SortDescClass())
{
    ui->setupUi(this);

    connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
    connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

    multimap<int, string, greater<int>> sortedMap = sortWordsDesc();
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

multimap<int, string, greater<int>> SortDesc::sortWordsDesc() 
{
    multimap<int, string, greater<int>> sortedMap;
    for (auto i : GlobalFunctions::localFrequencies)
    {
        sortedMap.insert({ i.second, i.first });
    }
    return sortedMap;
}

//another way to sortDesc

//vector<pair<string, int>> SortDesc::sortWordDesc(unordered_map<string, int>& paragraph)
//{
//    vector<pair<string, int>> vec(paragraph.begin(), paragraph.end());
//
//    bool swapped;
//    do
//    {
//        swapped = false;
//        for (int i = 0; i < vec.size() - 1; ++i)
//        {
//            if (vec[i].second < vec[i + 1].second)
//            {
//                swap(vec[i], vec[i + 1]);
//                swapped = true;
//            }
//        }
//    } while (swapped);
//
//    return vec;
//}


SortDesc::~SortDesc()
{
    delete ui;
}
