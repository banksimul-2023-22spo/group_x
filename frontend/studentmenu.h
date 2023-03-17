#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class StudentMenu;
}

class StudentMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMenu(QWidget *parent = nullptr);
    ~StudentMenu();

    QString getUsername() const;
    void setUsername(const QString &newUsername);

    void setToken(const QByteArray &newToken);

private slots:
    void on_btnMyData_clicked();
    void getMyDataSlot (QNetworkReply *reply);
    void getMyGradesSlot (QNetworkReply *reply);

    void on_btnGrades_clicked();

private:
    Ui::StudentMenu *ui;
    QString username;
    QByteArray token;
    QNetworkAccessManager *myDataManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // STUDENTMENU_H
