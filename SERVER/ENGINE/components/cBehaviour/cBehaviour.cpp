#include "../../../INCLUDE/cBehaviour.hpp"

cBehaviour::cBehaviour()
{
    
}

cBehaviour::~cBehaviour()
{
    
}

eComponentList cBehaviour::getComponentType()
{
    return behaviour;
}

iComponent* cBehaviour::clone()
{
    return new cBehaviour;
}
