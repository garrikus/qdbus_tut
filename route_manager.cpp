#include "route_manager.h"

RouteManager::RouteManager()
{
    m_adaptor = new RouteManagerAdaptor(this);
    m_nvsdData = new NvsdDataIface("sn.ornap.nvsd", "/navsensor",
                                   QDBusConnection::sessionBus(), this);

    for (unsigned i = 0; i < maxRoutesManaged; ++i)
        connect(m_nvsdData, SIGNAL(PositionFix(double,double,double,double,double,double,uint,uint,double,uchar)),
                &routeArray[i], SLOT(processIncomingFix(double,double,double,double,double,double,uint,uint,double,uchar)));
}

QDBusObjectPath RouteManager::StartNav(double lat, double lon)
{
    for(unsigned i = 0; i < maxRoutesManaged; ++i)
        if (routeArray[i].registerOnDbusWithId(connection(), i+1)) {
            routeArray[i].WptSet(lat, lon);
            return QDBusObjectPath(routeArray[i].getDBusPath());
        }

    sendErrorReply(QDBusError::Failed, "Cant register another route object.");
    return QDBusObjectPath("/");
}

void RouteManager::StopNav(const QDBusObjectPath &route_path)
{
    for(unsigned i = 0; i < maxRoutesManaged; ++i)
        if (route_path.path() == routeArray[i].getDBusPath()) {
            routeArray[i].unRegisterOnDbus(connection());
        }

    return;
}
