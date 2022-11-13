/*
** EPITECH PROJECT, 2022
** source
** File description:
** Weapon
*/

#include "iComponent.hpp"

#pragma once

class cWeapon : public iComponent {
    public: 
        cWeapon(int damage, float firerate);
        ~cWeapon();
        eComponentList getComponentType() override;
        iComponent *clone() override;
    private:
        int _damage;
        float _firerate;
};