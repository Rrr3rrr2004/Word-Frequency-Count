#include <QMainWindow>
#include "ui_SortDesc.h"
using namespace std;
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
