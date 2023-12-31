#ifndef DRUGMANAGEMENT_H
#define DRUGMANAGEMENT_H

#include <QWidget>

namespace Ui {
class DrugManagement;
}

class DrugManagement : public QWidget
{
    Q_OBJECT

public:
    explicit DrugManagement(QWidget *parent = nullptr);
    ~DrugManagement();

private:
    Ui::DrugManagement *ui;
};

#endif // DRUGMANAGEMENT_H
