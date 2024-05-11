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
    static QString QParagraph;
    static QString allTexts;
    static QString filePath;

    static unordered_map<string, int> localFrequencies;
    static unordered_map<string, int> globalFrequencies;

    //Files functions
    static void writeToFile();
    static void readFile(const QString& filePath, QString& text);
    static void readAllTexts();

    static vector<string> stringToVector(string text);
    static string vectorToString(vector<string> text);

    static  unordered_map<string, int> countWordFrequency(QString paragraph);

    static int deleteFromText(const QString& text, bool& flag);
    static void autoComplete(const QString& word, QStringListModel* wordsModel, QCompleter* autoCompleter);

    static string autoCorrect(const string& searchTerm);
    static void autoCorrection(QLineEdit* lineEdit, QString& text);
    static int calculateDistance(const string& word1, const string& word2);
    static QString getLastWord(const QString& text);
    //static QVector<QString> LoadDictionary(const QString& filepath);

};