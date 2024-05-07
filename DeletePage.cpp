#include "DeletePage.h"
#include <QPixmap> 
#include <QMessageBox>

DeletePage::DeletePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DeletePageClass())
{
	ui->setupUi(this);
	QPixmap deleteLogo("./icons/delete.png");
	ui->deleteLogo->setPixmap(deleteLogo.scaled(50, 50, Qt::KeepAspectRatio));
	//connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));
	//connect(ui->next, SIGNAL(triggered()), this, SLOT(moveToFinal()));

}

DeletePage::~DeletePage()
{
	delete ui;
}
