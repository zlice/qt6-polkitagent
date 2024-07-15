#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include <QDialog>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QIcon>
#include <QTimer>
#include <QDateTime>
#include <QDBusInterface>
#include <QApplication>
#include <QProcess>
#include <QPushButton>
#include <QComboBox>
#include <QScreen>
#include <QGuiApplication>
#include <QtGui/qguiapplication_platform.h>
#include <polkit-qt5-1/PolkitQt1/Identity>

#include <X11/Xlib.h>
#include <X11/Xatom.h>

#undef None
#undef Bool

namespace Ui {
class Authenticate;
}

class Authenticate : public QDialog
{
    Q_OBJECT

public:
    explicit Authenticate(QWidget *parent = 0);
    ~Authenticate();

    QString getPassword();
    void showFullScreen(bool showError = false);

    void setGeometry(int x, int y, int w, int h);
    void setGeometry(QRect geometry);

signals:
    void okClicked();

    void newUser(PolkitQt1::Identity newUser);

public slots:
    void setMessage(QString message);

    void setUser(QString user);

    void setUsers(PolkitQt1::Identity::List users);

    void setIcon(QIcon icon);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_authenticationUsers_currentIndexChanged(int index);

private:
    Ui::Authenticate *ui;
    QGraphicsOpacityEffect *fadeEffect;
};
Q_DECLARE_METATYPE(PolkitQt1::Identity)

#endif // AUTHENTICATE_H
