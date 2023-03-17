#include "mygrades.h"
#include "ui_mygrades.h"

MyGrades::MyGrades(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyGrades)
{
    ui->setupUi(this);
}

MyGrades::~MyGrades()
{
    delete ui;
}

void MyGrades::setGrades(const QString &newGrades)
{
    grades = newGrades;
    ui->textGrades->setText(grades);
}
