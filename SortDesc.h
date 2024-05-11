

#include <QMainWindow>
#include "ui_SortDesc.h"
#include <QMessageBox>
#include "OperationsPage.h"
#include "FinalPage.h"
#include "GlobalFunctions.h"

class SortDesc : public QMainWindow
{
    Q_OBJECT

public:
    SortDesc(QWidget* parent = nullptr);
    static multimap<int, string, greater<int>> sortWordsDesc();
    ~SortDesc();

private slots:
    void moveToOperations();
    void moveToFinal();

private:
    Ui::SortDescClass* ui;
};
