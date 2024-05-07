#include "SearchPage.h"

SearchPage::SearchPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SearchPageClass())
{
	ui->setupUi(this);
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	//connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToFinal()));
}

SearchPage::~SearchPage()
{
	delete ui;
}
