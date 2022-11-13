#include "../INCLUDE/Entity.hpp"

Entity::Entity(size_t id, size_t type)
{
    _id = id;
    _entityType = type;
    _isFree = false;
}

void Entity::freeMe()
{
    _isFree = true;
}

bool Entity::free()
{
    return _isFree;
}

Entity::~Entity()
{
    
}
