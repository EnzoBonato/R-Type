/*
** EPITECH PROJECT, 2022
** source
** File description:
** Weapon
*/

#include "iComponent.hpp"

#pragma once

class cControllable : public iComponent {
    public: 
        cControllable();
        ~cControllable();
        bool isControllable();
        eComponentList getComponentType() override;
        iComponent *clone() override;
    private:
        bool _isControllable;
};