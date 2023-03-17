#include "studentmenu.h"
#include "ui_studentmenu.h"

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
