#include "MainWindow.h"
#include "HomePage.h"

#include <QPixmap> 
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClass())
{
    ui->setupUi(this);
    QPixmap logo("./icons/search.png");
    ui->logo->setPixmap(logo.scaled(75, 75, Qt::KeepAspectRatio));
    connect(ui->quit, SIGNAL(clicked()), this, SLOT(quitProgram()));
    connect(ui->start, SIGNAL(clicked()), this, SLOT(moveToHome()));
    connect(ui->close, SIGNAL(triggered()), this, SLOT(quitProgram()));
}

void MainWindow::moveToHome()
{
    //try 
    hide();
    homePage = new HomePage();
    homePage->show();
}

void MainWindow::quitProgram()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
        "Do you want to close the program?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    //
}

/* critical
    information
    question
    warning*/