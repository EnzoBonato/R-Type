/*
** EPITECH PROJECT, 2022
** source
** File description: 
** iComponent
*/

#include <string>
#include <iostream>
#pragma once

enum eComponentList
{
    graphical = 0,
    weapon = 1,
    controllable = 2,
    collision = 3,
    speed = 4,
    scene = 5,
    text = 6,
    behaviour = 7,
    shape = 8,
    componentsNumber
};

class iComponent {
    public:
        virtual eComponentList getComponentType() = 0;
        virtual iComponent *clone() = 0;
        virtual ~iComponent() = default;
    private:
        size_t _ownerId;
        std::string _componentName;
};