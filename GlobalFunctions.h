#pragma once
#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QTextEdit>
#include <QString>
#include <map>
#include <vector>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCoreApplication>
#include <QFileDialog>
#include <QFile>
#include <QPixmap> 
#include <QMessageBox>
#include <QStringListModel>
#include <QCompleter>




using namespace std;

class GlobalFunctions
{
public:
    static QString QParagraph;
    //static string paragraph;
    static QString allTexts;
    static QString filePath;

    static unordered_map<string, int> localFrequencies;
    static unordered_map<string, int> globalFrequencies;

    //Files functions
    static void writeToFile();
    static void readFile();
    static void readAllTexts();

    static vector<string> stringToVector(string text);
    static string vectorToString(vector<string> text);

    static  unordered_map<string, int> countWordFrequency(QString paragraph);

    static int deleteFromText(const QString& text, bool& flag);
    static void autoComplete(const QString& word, QStringListModel* wordsModel, QCompleter* autoCompleter);
};