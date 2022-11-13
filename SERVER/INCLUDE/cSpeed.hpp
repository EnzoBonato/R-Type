/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** cSpeed
*/

#include "iComponent.hpp"
#include "SFML/System/Vector2.hpp"

#pragma once

class cSpeed : public iComponent
{
public:
    cSpeed();
    cSpeed(float x, float y);
    cSpeed(float x, float y, int dece_rate);
    cSpeed(cSpeed* cpy);
    ~cSpeed();
    void setSpeed(float x, float y);
    void accelerate(float x, float y);
    void deccelerate();
    void setX(float x);
    void setY(float y);
    sf::Vector2f getSpeed();
    eComponentList getComponentType() override;
    iComponent *clone() override;
private:
    float _x;
    float _y;
    int _deceleration_rate;
};
