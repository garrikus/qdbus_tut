#ifndef ROUTE_CONTROLS_H
#define ROUTE_CONTROLS_H

#include <QObject>
#include <route_controls_adp.h>

class RouteControls : public QObject
{
    Q_OBJECT
public:
    RouteControls();

public Q_SLOTS:
    void WptSet(double lat, double lon);
    void WptGet(double &lat, double &lon);
private:
    RouteControlsAdaptor *m_adaptor;

    double m_lat;
    double m_lon;
};


#endif // ROUTE_CONTROLS_H
