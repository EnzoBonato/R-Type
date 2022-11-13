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
    collision2 = 1, // collide with (collision3 and Out of map)
    collision3 = 2, // collide with (collision1, collision2 and Out of map)
};


class cCollision  final: public iComponent {
    public: 
        cCollision(eCollisionType type, float invuTime, int life, int bodyDamage);
        eComponentList getComponentType() override;
        iComponent *clone() override;
        eCollisionType getCollisionType();
        int getLife();
        int decreaseLife(int i);
        int getBodyDamage();
        bool isInvulnerable();
        void Destroy() { delete this; }
        ~cCollision();
    private:
        eCollisionType _type;
        int _bodyDamage;
        sf::Clock _invu;
        float _invuTime;
        int _life;
};


