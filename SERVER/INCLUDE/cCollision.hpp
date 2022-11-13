/*
** EPITECH PROJECT, 2022
** source
** File description:
** Collision
*/

#include "iComponent.hpp"
#include "SFML/System/Clock.hpp"

#pragma once

enum eCollisionType {
    collision1 = 0, // Collide with (collision3 and border)
    collision2 = 1, // collide with (collision3)
    collision3 = 2, // collide with (collision1)
};


class cCollision : public iComponent {
    public: 
        cCollision(eCollisionType type);
        ~cCollision();
        eComponentList getComponentType() override;
        iComponent *clone() override;
        eCollisionType getCollisionType();
    private:
        eCollisionType _type;
};