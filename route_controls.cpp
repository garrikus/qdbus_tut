#include "route_controls.h"

RouteControls::RouteControls():
    m_lat(0.0),
    m_lon(0.0),
    m_dbusId(0)
{
    m_adaptor = new RouteControlsAdaptor(this);
}

bool RouteControls::registerOnDbusWithId(QDBusConnection conn, unsigned id)
{
    if (m_dbusId)
        return false;
    else
        m_dbusId = id;

    if (conn.registerObject(getDBusPath(), this)) {
        return true;
    }

    m_dbusId = 0;
    return false;
}

void RouteControls::unRegisterOnDbus(QDBusConnection conn)
{
    if (m_dbusId) {
        conn.unregisterObject(getDBusPath());
    }

    m_dbusId = 0;
}

void RouteControls::WptSet(double lat, double lon)
{
    m_lat = lat;
    m_lon = lon;
}

void RouteControls::WptGet(double &lat, double &lon)
{
    lat = m_lat;
    lon = m_lon;
}

void RouteControls::processIncomingFix(double lat, double lon, double alt, double v_lat, double v_lon, double v_alt, uint date, uint time, double rms2d, uchar status)
{
    if (m_dbusId)
        emit Data(m_lat - lat, m_lon - lon);
}

QString RouteControls::getDBusPath() const
{
    return QString().sprintf("/routes/%d", m_dbusId);
}
