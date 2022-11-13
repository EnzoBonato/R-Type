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
