#include "UpdatePage.h"
#include "MainWindow.h"

UpdatePage::UpdatePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::UpdatePageClass())
{
	ui->setupUi(this);
	QPixmap update("./icons/update.png");
	ui->update->setPixmap(update.scaled(50, 50, Qt::KeepAspectRatio));
	//connect(ui->next, SIGNAL(clicked()), this, SLOT(moveToOperations()));
	connect(ui->back, SIGNAL(triggered()), this, SLOT(moveToOperations()));

}

//code of all move to operations function
void UpdatePage::moveToOperations()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmtion",
		"Do you want to discard your changes?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		hide();
		operationsPage = new OperationsPage();
		operationsPage->show();
	}
}

UpdatePage::~UpdatePage()
{
	delete ui;
}
