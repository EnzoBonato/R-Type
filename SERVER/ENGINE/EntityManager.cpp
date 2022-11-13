#include "../INCLUDE/EntityManager.hpp"

EntityManager::EntityManager()
{
    _lastEntity = 0;
}

EntityManager::~EntityManager()
{
    
}

void EntityManager::addEntity(size_t type)
{
    _entities.push_back(Entity(_lastEntity, type));
    _lastEntity++;
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
    
}