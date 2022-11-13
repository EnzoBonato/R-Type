#include "../INCLUDE/EntityManager.hpp"

EntityManager::EntityManager()
{
    _lastEntity = 0;
    _nextOne = 0;
}

EntityManager::~EntityManager()
{
    
}

void EntityManager::addEntity(size_t type)
{
    if (_freePlaces.size() == 0) {
        _nextOne = _entities.size();
        _entities.push_back(Entity(_lastEntity, type));
    } else {
        _nextOne = _freePlaces.back();
        _freePlaces.pop_back();
        _entities[_nextOne];
    }
}

size_t EntityManager::getLastEntity()
{
    return _lastEntity;
}

size_t EntityManager::getFirstPlaceAvailible()
{
    return _firstPlaceAvailible;
}

size_t EntityManager::getLastEntityCreated()
{
    return _lastEntityCreated;
}

void EntityManager::removeEntity(size_t r)
{
    _freePlaces.push_back(r);
    _entities[r].freeMe();
    
}

size_t EntityManager::getFreePlace()
{
    return _nextOne;
}
