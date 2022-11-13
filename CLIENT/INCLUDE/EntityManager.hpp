#include "Entity.hpp"
#include "ComponentsManager.hpp"

#pragma once

class EntityManager
{
public:
    void addEntity(size_t entityType);
    size_t getLastEntity();
    size_t getFirstPlaceAvailible();
    size_t getLastEntityCreated();
    size_t getFreePlace();
    void removeEntity(size_t r);
    EntityManager();
    ~EntityManager();
private:
    std::vector<Entity> _entities;
    std::vector<size_t> _freePlaces;
    size_t _nextOne;
    size_t _lastEntity;
    size_t _firstPlaceAvailible;
    size_t _lastEntityCreated;
};

























