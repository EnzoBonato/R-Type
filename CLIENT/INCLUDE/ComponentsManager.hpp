/*
** EPITECH PROJECT, 2022
** source
** File description:
** componentsManager
*/

#pragma once

#include "cGraphical.hpp"
#include "cWeapon.hpp"
#include "cControllable.hpp"
#include "cCollision.hpp"
#include "cSpeed.hpp"
#include "cText.hpp"
#include "cScene.hpp"
#include "cBehaviour.hpp"
#include "cBarLife.hpp"
#include "ComponentsFactory.hpp"
#include <map>

class ComponentsManager
{
public:
    ComponentsManager();
    void addEntity(size_t entity);
    void addEntity(size_t entity, size_t index);
    void addEntity(size_t entity, size_t index, sf::Vector2f pos);
    void check();
    std::vector<cGraphical*> &getGraphicalComponents();
    std::vector<cControllable*> &getControllableComponents();
    std::vector<cSpeed*> &getSpeedComponents();
    std::vector<cCollision*> &getCollisionsComponents();
    std::vector<cScene*> &getSceneComponents();
    std::vector<cText*> &getTextComponents();
    std::vector<cBehaviour*> &getBehaviourComponents();
    std::vector<cShape*> &getShapeComponents();
    ~ComponentsManager();
private:
    std::vector<cGraphical*> _graphicalComponents;
    std::vector<cWeapon*> _weaponComponents;
    std::vector<cControllable*> _controllableComponents;
    std::vector<cCollision*> _collisionComponents;
    std::vector<cSpeed*> _speedComponents;
    std::vector<cScene*> _sceneComponents;
    std::vector<cText*> _textComponents;
    std::vector<cBehaviour*> _behaviourComponents;
    std::vector<cShape*> _shapeComponents;
    ComponentsFactory _compFactory;
};
