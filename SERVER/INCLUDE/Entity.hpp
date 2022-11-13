/*
** EPITECH PROJECT, 2022
** source
** File description:
** Entity
*/

#include <vector>
#include "iComponent.hpp"
#pragma once

class Entity {
    public:
        Entity(size_t id, size_t type);
        ~Entity();
    private:
        size_t _id;
        size_t _entityType;
};

