#include "mainwindow.h"
#include "studentmenu.h"
#include "ui_mainwindow.h"
#include "environment.h"
#include "QDebug"

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
    QJsonObject jsonObj;
    jsonObj.insert("username",username);
    jsonObj.insert("password",password);


    QString site_url=Environment::getBaseUrl()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());


}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    if(QString::compare(response_data,"-4078")==0 || response_data.length()==0){
        ui->labelInfo->setText("Virhe tietokantayhteydessä");
    }
    else {
    if(QString::compare(response_data, "false")!=0){
        ui->labelInfo->setText("Login OK");
        token="Bearer "+response_data;
        qDebug()<<token;
        StudentMenu *objectStudentMenu=new StudentMenu(this);
        objectStudentMenu->setUsername(username);
        objectStudentMenu->setToken(token);
        objectStudentMenu->open();
    }
    else{
        ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
        ui->textUsername->clear();
        ui->textPassword->clear();
    }
    }

    reply->deleteLater();
    loginManager->deleteLater();
}

