/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** cSpeed
*/

#include "../../../INCLUDE/cSpeed.hpp"

cSpeed::cSpeed()
{
    _x = 0;
    _y = 0;
    _deceleration_rate = 0;
}

cSpeed::cSpeed(float x, float y)
{
    _x = x;
    _y = y;
    _deceleration_rate = 0;
}

cSpeed::cSpeed(float x, float y, int dece_rate)
{
    _x = x;
    _y = y;
    _deceleration_rate = dece_rate;
}

cSpeed::~cSpeed()
{
    
}

void cSpeed::setSpeed(float x, float y)
{
    _x = x;
    _y = y;
}

void cSpeed::accelerate(float x, float y)
{
    _x += x;
    _y += y;
}

void cSpeed::deccelerate()
{
    if (_deceleration_rate == 0)
        return;
    _x += (0 - _x / _deceleration_rate);
    _y += (0 - _y / _deceleration_rate);
}

void cSpeed::setX(float x)
{
    _x = x;
}

void cSpeed::setY(float y)
{
    _y = y;
}

sf::Vector2f cSpeed::getSpeed()
{
    return sf::Vector2f(_x, _y);
}

eComponentList cSpeed::getComponentType()
{
    return speed;
}

iComponent* cSpeed::clone()
{
    return new cSpeed(_x, _y, _deceleration_rate);
}
