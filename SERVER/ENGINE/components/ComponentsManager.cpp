#include "../../INCLUDE/ComponentsManager.hpp"

ComponentsManager::ComponentsManager()
{
    std::vector<cCollision*> a;
    _collisionComponents.push_back(a);
    _collisionComponents.push_back(a);
    _collisionComponents.push_back(a);
}

void ComponentsManager::addEntity(size_t entity)
{
    std::vector<iComponent*> compToAdd = _compFactory.createComponentsVector(entity);

    _graphicalComponents.push_back(nullptr);
    _weaponComponents.push_back(nullptr);
    _controllableComponents.push_back(nullptr);
    _collisionComponents[0].push_back(nullptr);
    _collisionComponents[1].push_back(nullptr);
    _collisionComponents[2].push_back(nullptr);
    _speedComponents.push_back(nullptr);
    _sceneComponents.push_back(nullptr);
    _textComponents.push_back(nullptr);
    _behaviourComponents.push_back(nullptr);

    for (size_t i = 0; i != compToAdd.size(); i++) {
        if (compToAdd[i]->getComponentType() == eComponentList::graphical)
            _graphicalComponents[_graphicalComponents.size() - 1] = (dynamic_cast<cGraphical*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::weapon)
            _weaponComponents[_graphicalComponents.size() - 1] = (dynamic_cast<cWeapon*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::controllable)
            _controllableComponents[_graphicalComponents.size() - 1] = (dynamic_cast<cControllable*>(compToAdd[i]));
        if (compToAdd[i]->getComponentType() == eComponentList::collision) {            
            if (dynamic_cast<cCollision*>(compToAdd[i])->getCollisionType() == collision1)
                _collisionComponents[0][_graphicalComponents.size() - 1] = (dynamic_cast<cCollision*>(compToAdd[i]));
            if (dynamic_cast<cCollision*>(compToAdd[i])->getCollisionType() == collision2)
                _collisionComponents[1][_graphicalComponents.size() - 1] = (dynamic_cast<cCollision*>(compToAdd[i]));
            if (dynamic_cast<cCollision*>(compToAdd[i])->getCollisionType() == collision3)
                _collisionComponents[2][_graphicalComponents.size() - 1] = (dynamic_cast<cCollision*>(compToAdd[i]));
        }
        if (compToAdd[i]->getComponentType() == eComponentList::speed)
            _speedComponents[_graphicalComponents.size() - 1] = (dynamic_cast<cSpeed*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::scene)
            _sceneComponents[_graphicalComponents.size() - 1] = (dynamic_cast<cScene*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::text)
            _textComponents[_graphicalComponents.size() - 1] = (dynamic_cast<cText*>(compToAdd[i]));   
        if (compToAdd[i]->getComponentType() == eComponentList::behaviour)
            _behaviourComponents[_graphicalComponents.size() - 1] = (dynamic_cast<cBehaviour*>(compToAdd[i]));   
    }
}

void ComponentsManager::check()
{
}

std::vector<cBehaviour*> ComponentsManager::getBehaviourComponents()
{
    return _behaviourComponents;
}


std::vector<cText*> ComponentsManager::getTextComponents()
{
    return _textComponents;
}

std::vector<cScene*> ComponentsManager::getSceneComponents()
{
    return _sceneComponents;
}

std::vector<cGraphical*> ComponentsManager::getGraphicalComponents()
{
    return _graphicalComponents;
}

std::vector<cControllable*> ComponentsManager::getControllableComponents()
{
    return _controllableComponents;
}

std::vector<cSpeed*> ComponentsManager::getSpeedComponents()
{
    return _speedComponents;
}

std::vector<std::vector<cCollision*>> ComponentsManager::getCollisionsComponents()
{
    return _collisionComponents;
}

ComponentsManager::~ComponentsManager()
{
}
