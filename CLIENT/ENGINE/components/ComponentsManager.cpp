#include "../../INCLUDE/ComponentsManager.hpp"

ComponentsManager::ComponentsManager()
{
}

void ComponentsManager::addEntity(size_t entity, size_t index, sf::Vector2f pos)
{
    std::vector<iComponent*> compToAdd = _compFactory.createComponentsVector(entity, pos);

    if (index == _graphicalComponents.size()) {
        _graphicalComponents.push_back(nullptr);
        _weaponComponents.push_back(nullptr);
        _controllableComponents.push_back(nullptr);
        _collisionComponents.push_back(nullptr);
        _speedComponents.push_back(nullptr);
        _sceneComponents.push_back(nullptr);
        _textComponents.push_back(nullptr);
        _behaviourComponents.push_back(nullptr);
    }

    for (size_t i = 0; i != compToAdd.size(); i++) {
        if (compToAdd[i]->getComponentType() == eComponentList::graphical)
            _graphicalComponents[index] = (dynamic_cast<cGraphical*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::weapon)
            _weaponComponents[index] = (dynamic_cast<cWeapon*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::controllable)
            _controllableComponents[index] = (dynamic_cast<cControllable*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::collision)
            _collisionComponents[index] = (dynamic_cast<cCollision*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::speed)
            _speedComponents[index] = (dynamic_cast<cSpeed*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::scene)
            _sceneComponents[index] = (dynamic_cast<cScene*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::text)
            _textComponents[index] = (dynamic_cast<cText*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::behaviour)
            _behaviourComponents[index] = (dynamic_cast<cBehaviour*>(compToAdd[i]));   
    }
}

void ComponentsManager::addEntity(size_t entity, size_t index)
{
    std::vector<iComponent*> compToAdd = _compFactory.createComponentsVector(entity);

    if (index == _graphicalComponents.size()) {
        _graphicalComponents.push_back(nullptr);
        _weaponComponents.push_back(nullptr);
        _controllableComponents.push_back(nullptr);
        _collisionComponents.push_back(nullptr);
        _speedComponents.push_back(nullptr);
        _sceneComponents.push_back(nullptr);
        _textComponents.push_back(nullptr);
        _behaviourComponents.push_back(nullptr);
    }

    for (size_t i = 0; i != compToAdd.size(); i++) {
        if (compToAdd[i]->getComponentType() == eComponentList::graphical)
            _graphicalComponents[index] = (dynamic_cast<cGraphical*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::weapon)
            _weaponComponents[index] = (dynamic_cast<cWeapon*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::controllable)
            _controllableComponents[index] = (dynamic_cast<cControllable*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::collision)
            _collisionComponents[index] = (dynamic_cast<cCollision*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::speed)
            _speedComponents[index] = (dynamic_cast<cSpeed*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::scene)
            _sceneComponents[index] = (dynamic_cast<cScene*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::text)
            _textComponents[index] = (dynamic_cast<cText*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::behaviour)
            _behaviourComponents[index] = (dynamic_cast<cBehaviour*>(compToAdd[i]));   
    }
}

void ComponentsManager::check()
{
}

std::vector<cShape*> &ComponentsManager::getShapeComponents()
{
    return _shapeComponents;
}

std::vector<cBehaviour*> &ComponentsManager::getBehaviourComponents()
{
    return _behaviourComponents;
}

std::vector<cText*> &ComponentsManager::getTextComponents()
{
    return _textComponents;
}

std::vector<cScene*> &ComponentsManager::getSceneComponents()
{
    return _sceneComponents;
}

std::vector<cGraphical*> &ComponentsManager::getGraphicalComponents()
{
    return _graphicalComponents;
}

std::vector<cControllable*> &ComponentsManager::getControllableComponents()
{
    return _controllableComponents;
}

std::vector<cSpeed*> &ComponentsManager::getSpeedComponents()
{
    return _speedComponents;
}

std::vector<cCollision*> &ComponentsManager::getCollisionsComponents()
{
    return _collisionComponents;
}

ComponentsManager::~ComponentsManager()
{
}
