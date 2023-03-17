#ifndef MYDATA_H
#define MYDATA_H

#include <QDialog>

namespace Ui {
class MyData;
}

class MyData : public QDialog
{
    Q_OBJECT

public:
    explicit MyData(QWidget *parent = nullptr);
    ~MyData();

    void setMyData(const QString &newMyData);

private:
    Ui::MyData *ui;
    QString myData;
};

#endif // MYDATA_H
