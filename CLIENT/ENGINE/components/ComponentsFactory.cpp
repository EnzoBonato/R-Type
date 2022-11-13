#include "../../INCLUDE/ComponentsFactory.hpp"

ComponentsFactory::ComponentsFactory(/* args */)
{
}

ComponentsFactory::~ComponentsFactory()
{
}

std::vector<iComponent *> ComponentsFactory::createComponentsVector(size_t entityToLoad)
{
    return this->_lib.getVectorComponents(entityToLoad);
}

std::vector<iComponent *> ComponentsFactory::createComponentsVector(size_t entityToLoad, sf::Vector2f pos)
{
    auto a = this->_lib.getVectorComponents(entityToLoad);
    for (size_t i = 0; i != a.size(); i++) {
        if (a[i]->getComponentType() == graphical)
            (dynamic_cast<cGraphical*>(a[i])->getSprite().setPosition(pos));
    }
    return a;
}