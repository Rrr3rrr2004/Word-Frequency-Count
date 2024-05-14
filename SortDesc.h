#include <QMainWindow>
#include "ui_SortDesc.h"
using namespace std;
class SortDesc : public QMainWindow
{
    Q_OBJECT

public:
    SortDesc(QWidget* parent = nullptr);
    static multimap<int, string, greater<int>> sortWordsDesc();
    //static vector<pair<string, int>> SortDesc::sortWordDesc(unordered_map<string, int>& paragraph);
    ~SortDesc();

private slots:
    void moveToOperations();
    void moveToFinal();

private:
    Ui::SortDescClass* ui;
};