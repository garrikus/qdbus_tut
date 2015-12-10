#include <QCoreApplication>
#include <QDBusConnection>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDBusConnection conn = QDBusConnection::sessionBus();
    conn.registerService("sn.ornap.skeleton");


    return a.exec();
}
