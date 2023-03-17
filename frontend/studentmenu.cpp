#include "studentmenu.h"
#include "ui_studentmenu.h"
#include "environment.h"

#include <MyData.h>

StudentMenu::StudentMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentMenu)
{
    ui->setupUi(this);
}

StudentMenu::~StudentMenu()
{
    delete ui;
}

QString StudentMenu::getUsername() const
{
    return username;
}

void StudentMenu::setUsername(const QString &newUsername)
{
    username = newUsername;
    ui->labelStudentInfo->setText("Tervetuloa "+username);
}

void StudentMenu::setToken(const QByteArray &newToken)
{
    token = newToken;
}

void StudentMenu::on_btnMyData_clicked()
{
    QString site_url=Environment::getBaseUrl()+"/student/"+username;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    myDataManager = new QNetworkAccessManager(this);

    connect(myDataManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getMyDataSlot(QNetworkReply*)));

    reply = myDataManager->get(request);
}

void StudentMenu::getMyDataSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString data;
    data=json_obj["fname"].toString()+"\r\n"+json_obj["lname"].toString();

    //ui->labelStudentInfo->setText(data);
    MyData *objectMyData=new MyData(this);
    objectMyData->setMyData(data);
    objectMyData->open();

    reply->deleteLater();
    myDataManager->deleteLater();
}

