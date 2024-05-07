#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class HomePage;

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
