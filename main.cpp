#include "polkitinterface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    PolkitInterface* interface = new PolkitInterface();
    PolkitQt1::UnixSessionSubject subject(QApplication::applicationPid());
    interface->registerListener(subject, "/com/iskrembilen/polkitAuthAgent");

    return a.exec();

}
