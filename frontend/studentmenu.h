#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <QDialog>

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

private:
    Ui::StudentMenu *ui;
    QString username;
};

#endif // STUDENTMENU_H
