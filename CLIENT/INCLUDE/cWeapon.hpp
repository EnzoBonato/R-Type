/*
** EPITECH PROJECT, 2022
** source
** File description:
** Weapon
*/

#include "iComponent.hpp"

#pragma once

class cWeapon  final: public iComponent {
    public: 
        cWeapon(int damage, float firerate);
        eComponentList getComponentType() override;
        iComponent *clone() override;
        virtual void Destroy() { delete this; }
        ~cWeapon();
    private:
        int _damage;
        float _firerate;
};