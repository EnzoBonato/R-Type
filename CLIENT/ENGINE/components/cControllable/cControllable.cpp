#include "../../../INCLUDE/cControllable.hpp"

eComponentList cControllable::getComponentType()
{
    return (eComponentList::controllable);
}

iComponent* cControllable::clone()
{
    return (new cControllable);
}

cControllable::cControllable()
{
}

cControllable::~cControllable()
{
}

bool cControllable::isControllable()
{
    return _isControllable;
}
