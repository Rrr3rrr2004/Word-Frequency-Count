#include "FinalPage.h"
#include "MainWindow.h"


FinalPage::FinalPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::FinalPageClass())
{
	ui->setupUi(this);
	QPixmap logo("./icons/search.png");
	ui->logo->setPixmap(logo.scaled(75, 75, Qt::KeepAspectRatio));
	//connect(ui->close, SIGNAL(triggered()), this, SLOT(quitProgram()));
	//connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToOperations()));
	//connect(ui->quit, SIGNAL(clicked()), this, SLOT(quitProgram()));

}

FinalPage::~FinalPage()
{
	delete ui;
}
