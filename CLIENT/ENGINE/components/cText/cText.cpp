#include "../../../INCLUDE/cText.hpp"

cText::cText(std::string path, int size, sf::Color col, std::string text)
{
    _font.loadFromFile(path);
    //_text.setFont(_font);
    _text.setFillColor(col);
    _text.setString(text);
    _text.setCharacterSize(size);
}

cText::cText(sf::Font font, int size, sf::Color col, std::string text)
{
    _font = font;
    _text.setFont(_font);
    _text.setFillColor(col);
    _text.setString(text);
    _text.setCharacterSize(size);    
}

sf::Text& cText::getText()
{
    return _text;
}

eComponentList cText::getComponentType()
{
    return text;
}

iComponent* cText::clone()
{
    cText *t = new cText(_font, _text.getCharacterSize(), _text.getFillColor(), _text.getString());
    t->getText().setPosition(this->getText().getPosition());
    return t;
}

cText::~cText()
{
    
}