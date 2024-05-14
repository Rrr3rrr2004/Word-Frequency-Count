#pragma once
#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QTextEdit>
#include <QString>
#include <map>
#include <unordered_map>
#include <Qset>
#include <vector>
#include <QVector>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QFile>
#include <QPixmap> 
#include <QMessageBox>
#include <QStringListModel>
#include <QCompleter>
#include <algorithm>
#include <QLineEdit>

using namespace std;

class GlobalFunctions
{
public:
    //Text
    static QString QParagraph;
    static QString allTexts;
    static QString filePath;
    //Frequencies
    static unordered_map<string, int> localFrequencies;
    static unordered_map<string, int> globalFrequencies;

    //Files functions
    static void writeToFile();
    static void readFile(const QString& filePath, QString& text);
    static void readAllTexts();

    static vector<string> stringToVector(string text);
    static string vectorToString(vector<string> text);
    static QString getLastWord(const QString& text);

    static  unordered_map<string, int> countWordFrequency(QString paragraph);

    static int deleteFromText(const QString& text, bool& flag);

    static void autoComplete(const QString& word, QStringListModel* wordsModel, QCompleter* autoCompleter);
    //autoCorrection functions
    static int calculateDistance(const string& word1, const string& word2);
    static string autoCorrect(const string& searchTerm);
    static void autoCorrection(QLineEdit* lineEdit, QString& text);
};