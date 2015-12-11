#include "route_manager.h"

RouteManager::RouteManager()
{
    m_adaptor = new RouteManagerAdaptor(this);
}

QDBusObjectPath RouteManager::StartNav(double lat, double lon)
{
    return QDBusObjectPath("/routes/useless_route");
}

void RouteManager::StopNav(const QDBusObjectPath &route_path)
{
    return;
}
