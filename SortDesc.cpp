#include "SortDesc.h"

SortDesc::SortDesc(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::SortDescClass())
{
	ui->setupUi(this);
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

}

SortDesc::~SortDesc()
{
	delete ui;
}
