#ifndef ROUTE_MANAGER_H
#define ROUTE_MANAGER_H

#include "route_manager_adp.h"
#include "route_controls.h"
#include <QObject>
#include <QDBusContext>
#include <QDBusObjectPath>

class RouteManager : public QObject, protected QDBusContext
{
    Q_OBJECT
public:
    static const std::size_t maxRoutesManaged = 20;
    RouteManager();

public Q_SLOTS:
    QDBusObjectPath StartNav(double lat, double lon);
    void StopNav(const QDBusObjectPath &route_path);

private:
    RouteManagerAdaptor *m_adaptor;
    RouteControls routeArray[maxRoutesManaged];
};

#endif // ROUTE_MANAGER_H
