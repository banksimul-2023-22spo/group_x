#include "mainwindow.h"
#include "studentmenu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLogin_clicked()
{
    username=ui->textUsername->text();
    QString password=ui->textPassword->text();
    if(QString::compare(username, "t2tete")==0){
        ui->labelInfo->setText("Login OK");
        StudentMenu *objectStudentMenu=new StudentMenu(this);
        objectStudentMenu->setUsername(username);
        objectStudentMenu->open();
    }
    else{
        ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
        ui->textUsername->clear();
        ui->textPassword->clear();
    }
}

