#ifndef ROUTE_MANAGER_H
#define ROUTE_MANAGER_H

#include "route_manager_adp.h"
#include <QObject>
#include <QDBusContext>
#include <QDBusObjectPath>

class RouteManager : public QObject
{
    Q_OBJECT
public:
    RouteManager();

public Q_SLOTS:
    QDBusObjectPath StartNav(double lat, double lon);
    void StopNav(const QDBusObjectPath &route_path);

private:
    RouteManagerAdaptor *m_adaptor;
};

#endif // ROUTE_MANAGER_H
