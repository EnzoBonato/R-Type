#include "iComponent.hpp"
#include <SFML/Graphics/Text.hpp>

#pragma once

class cText : public iComponent
{
public:
    cText(std::string path, int size, sf::Color col, std::string text);
    cText(sf::Font font, int size, sf::Color col, std::string text);
    sf::Text &getText();
    eComponentList getComponentType() override;
    iComponent *clone() override;
private:
    sf::Text _text;
    sf::Font _font;
};
