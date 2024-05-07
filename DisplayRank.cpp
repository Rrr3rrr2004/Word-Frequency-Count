#include "DisplayRank.h"

DisplayRank::DisplayRank(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DisplayRankClass())
{
	ui->setupUi(this);
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
}

DisplayRank::~DisplayRank()
{
	delete ui;
}
