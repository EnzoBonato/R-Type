/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** cShape
*/

#include "../../../INCLUDE/cBarLife.hpp"

cShape::cShape(sf::Color color, sf::Vector2f size)
{
    _color = color;
    _size = size;
    _lifebar.setFillColor(color);
    _lifebar.setSize(size);
}

sf::RectangleShape& cShape::getShape()
{
    return _lifebar;
}

eComponentList cShape::getComponentType()
{
    return shape;
}

iComponent* cShape::clone()
{
    cShape *t = new cShape(_color, _size);
    t->getShape().setPosition(this->getShape().getPosition());
    return t;
}

cShape::~cShape()
{
    
}