#include "WritePage.h"

WritePage::WritePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::WritePageClass())
{
	ui->setupUi(this);
}

WritePage::~WritePage()
{
	delete ui;
}
