#include "mydata.h"
#include "qdebug.h"
#include "ui_mydata.h"

MyData::MyData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyData)
{
    ui->setupUi(this);
    qDebug()<<"MyData object created";
}

MyData::~MyData()
{
    qDebug()<<"MyData object deleted";
    delete ui;
}

void MyData::setMyData(const QString &newMyData)
{
    myData = newMyData;
    ui->textData->setText(myData);
}
