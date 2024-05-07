#include "SortAsc.h"

SortAsc::SortAsc(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SortAscClass())
{
	ui->setupUi(this);
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

}

SortAsc::~SortAsc()
{
	delete ui;
}
