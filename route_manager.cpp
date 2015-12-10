#include "route_manager.h"


RouteManager::RouteManager()
{
    m_adaptor = new RouteManagerAdaptor(this);
}
