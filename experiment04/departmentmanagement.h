#ifndef DEPARTMENTMANAGEMENT_H
#define DEPARTMENTMANAGEMENT_H

#include <QWidget>

namespace Ui {
class DepartmentManagement;
}

class DepartmentManagement : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentManagement(QWidget *parent = nullptr);
    ~DepartmentManagement();

private:
    Ui::DepartmentManagement *ui;
};

#endif // DEPARTMENTMANAGEMENT_H
