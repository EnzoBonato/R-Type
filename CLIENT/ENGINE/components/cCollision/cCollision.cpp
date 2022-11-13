#include "../../../INCLUDE/cCollision.hpp"

cCollision::cCollision(eCollisionType type, float invuTIme, int life, int bodyDmg)
{
    _type = type;
    _life = life;
    _invuTime = invuTIme;
    _bodyDamage = bodyDmg;
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
    return (new cCollision(_type, _invuTime, _life, _bodyDamage));
}

eCollisionType cCollision::getCollisionType()
{
    return _type;
}

int cCollision::getLife()
{
    return _life;
}

int cCollision::decreaseLife(int i)
{
    if (_invu.getElapsedTime().asSeconds() < _invuTime)
        return _life;
    _life -= i;
    _invu.restart();
    return (_life);
}

bool cCollision::isInvulnerable()
{
    if (_invu.getElapsedTime().asSeconds() < _invuTime)
        return true;
    return false;
}


int cCollision::getBodyDamage()
{
    return _bodyDamage;
}
