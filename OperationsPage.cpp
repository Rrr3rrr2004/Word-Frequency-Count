#include "OperationsPage.h"

OperationsPage::OperationsPage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::OperationsPageClass())
{
	ui->setupUi(this);
}

OperationsPage::~OperationsPage()
{
	delete ui;
}
