#ifndef ROUTE_MANAGER_H
#define ROUTE_MANAGER_H

#include "route_manager_adp.h"
#include <QObject>
#include <QDBusContext>

class RouteManager : public QObject
{
    Q_OBJECT
public:
    RouteManager();

private:
    RouteManagerAdaptor *m_adaptor;
};

#endif // ROUTE_MANAGER_H
