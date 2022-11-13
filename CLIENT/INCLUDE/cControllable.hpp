/*
** EPITECH PROJECT, 2022
** source
** File description:
** Weapon
*/

#include "iComponent.hpp"

#pragma once

class cControllable final: public iComponent {
    public: 
        cControllable();
        bool isControllable();
        eComponentList getComponentType() override;
        iComponent *clone() override;
        void Destroy() { delete this; }
        ~cControllable();
    private:
        bool _isControllable;
};