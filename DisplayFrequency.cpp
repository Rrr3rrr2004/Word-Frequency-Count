#include "DisplayFrequency.h"

DisplayFrequency::DisplayFrequency(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DisplayFrequencyClass())
{
	ui->setupUi(this);
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
}

DisplayFrequency::~DisplayFrequency()
{
	delete ui;
}
