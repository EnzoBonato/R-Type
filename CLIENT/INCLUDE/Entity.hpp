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
        void freeMe();
        bool free();
        ~Entity();
    private:
        size_t _id;
        size_t _entityType;
        bool _isFree;
};



