#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

//pages
#include "OperationsPage.h"
#include "UploadFile.h"
#include "DisplayTextPage.h"
#include "HomePage.h"
#include "UpdatePage.h"
#include "WritePage.h"
#include "DeletePage.h"
#include "SortAsc.h"
#include "SortDesc.h"
#include "DisplayFrequency.h"
#include "DisplayRank.h"
#include "SearchPage.h"
#include "FinalPage.h"

#include "GlobalFunctions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void moveToHome();
    void quitProgram();

private:
    HomePage* homePage;
    Ui::MainWindowClass *ui;
};
