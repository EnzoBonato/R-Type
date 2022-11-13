#include "../../../INCLUDE/cWeapon.hpp"

eComponentList cWeapon::getComponentType()
{
    return (eComponentList::weapon);
}

iComponent* cWeapon::clone()
{
    return new cWeapon(_damage, _firerate);    
}

cWeapon::cWeapon(int damage, float firerate)
{
    _damage = damage;
    _firerate = firerate;
}

cWeapon::~cWeapon()
{
    
}
