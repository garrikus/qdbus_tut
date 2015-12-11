#ifndef ROUTE_CONTROLS_H
#define ROUTE_CONTROLS_H

#include <QObject>
#include <QDBusContext>
#include <QString>
#include <route_controls_adp.h>

class RouteControls : public QObject, protected QDBusContext
{
    Q_OBJECT
public:
    RouteControls();
    QString getDBusPath() const;
    void unRegisterOnDbus(QDBusConnection);
    bool registerOnDbusWithId(QDBusConnection, unsigned);

public Q_SLOTS:
    void WptSet(double lat, double lon);
    void WptGet(double &lat, double &lon);
private:
    RouteControlsAdaptor *m_adaptor;

    double m_lat;
    double m_lon;

    unsigned m_dbusId;
};


#endif // ROUTE_CONTROLS_H
