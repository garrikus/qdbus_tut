#include "route_controls.h"

RouteControls::RouteControls():
    m_lat(0.0),
    m_lon(0.0)
{
    m_adaptor = new RouteControlsAdaptor(this);
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
