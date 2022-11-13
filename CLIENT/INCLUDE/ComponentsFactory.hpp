/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** ComponentsFactory
*/

#pragma once

#include "iComponent.hpp"
#include "ComponentsLibrary.hpp"

class ComponentsFactory
{
public:
    ComponentsFactory(/* args */);
    ~ComponentsFactory();
    std::vector<iComponent *> createComponentsVector(size_t index, sf::Vector2f pos);
    std::vector<iComponent *> createComponentsVector(size_t index);

private:
    ComponentsLibrary _lib;
};
