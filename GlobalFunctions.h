#pragma once

using namespace std;
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

class GlobalFunctions
{
public:
    static QString QParagraph;
    static QString filePath;
    static string paragraph;

    static vector<string> stringToVector(const string& text);
    static void countWordFrequency();
};

