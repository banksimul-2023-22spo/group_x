#ifndef MYGRADES_H
#define MYGRADES_H

#include <QDialog>

namespace Ui {
class MyGrades;
}

class MyGrades : public QDialog
{
    Q_OBJECT

public:
    explicit MyGrades(QWidget *parent = nullptr);
    ~MyGrades();

    void setGrades(const QString &newGrades);

private:
    Ui::MyGrades *ui;
    QString grades;
};

#endif // MYGRADES_H
