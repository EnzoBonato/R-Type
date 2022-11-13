/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** cShape
*/

#include "iComponent.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

#pragma once

class cShape final: public iComponent {
    public: 
        cShape(sf::Color, sf::Vector2f);
        sf::RectangleShape& getShape();
        eComponentList getComponentType() override;
        iComponent *clone() override;
        void Destroy() { delete this; }
        ~cShape();
    private:
        sf::RectangleShape _lifebar;
        sf::Color _color;
        sf::Vector2f _size;
};