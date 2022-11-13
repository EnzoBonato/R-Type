#include "../../../INCLUDE/cCollision.hpp"

cCollision::cCollision(eCollisionType type)
{
    _type = type;
}

cCollision::~cCollision()
{
    
}

eComponentList cCollision::getComponentType()
{
    return eComponentList::collision;
}

iComponent* cCollision::clone()
{
    return (new cCollision(_type));
}

eCollisionType cCollision::getCollisionType()
{
    return _type;
}
