#include "SearchPage.h"

SearchPage::SearchPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SearchPageClass())
{
	ui->setupUi(this);
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

}

SearchPage::~SearchPage()
{
	delete ui;
}
