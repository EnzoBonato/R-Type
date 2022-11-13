/*
** EPITECH PROJECT, 2022
** source
** File description:
** Engine
*/

#include "../INCLUDE/Engine.hpp"

Engine::Engine(SafeQueue<RequestInfo> *queueReceive, SafeQueue<RequestInfo> *queueSend)
{
     _queueSend = queueSend;
     _queueReceive = queueReceive;
    _offset = {0, 0};
    addToIntRegister("MENU", 0);
    addToIntRegister("MENU_BIS", 0);
    addToIntRegister("OFFS_X", 0);
    addToIntRegister("OFFS_Y", 0);
    _menuState = GAME_SCENE;
}

Engine::~Engine()
{
    
}

void Engine::addEntityToGame(size_t entity)
{
    this->_entitiesManager.addEntity(entity);
    this->_componentsManager.addEntity(entity);
}

void Engine::check()
{
    _componentsManager.check();
}

void Engine::sControl(RequestInfo temp)
{
    std::cout << "REQUEST = " << temp._request;
    std::cout << " ID = " << temp._id;
    std::cout << " VALUE = " << temp._firstValue;
    std::cout << " VALUE = " << temp._secondValue<< std::endl;

    std::size_t index = std::stoi(temp._id);
    if (index < _componentsManager.getControllableComponents().size()) {
        if (_componentsManager.getControllableComponents()[index]) {
            if (temp._firstValue == "DOWN") {
                if (_componentsManager.getSpeedComponents()[index]) {
                    _componentsManager.getSpeedComponents()[index]->setY(10);
                    sDrawAll(temp);
                }
            }
            if (temp._firstValue == "UP") {
                if (_componentsManager.getSpeedComponents()[index]) {
                    _componentsManager.getSpeedComponents()[index]->setY(-10);
                    sDrawAll(temp);
                }
            }
            if (temp._firstValue == "LEFT") {
                if (_componentsManager.getSpeedComponents()[index]) {
                    _componentsManager.getSpeedComponents()[index]->setX(-10);
                    sDrawAll(temp);
                }
            }
            if (temp._firstValue == "RIGHT") {
                if (_componentsManager.getSpeedComponents()[index]) {
                    _componentsManager.getSpeedComponents()[index]->setX(10);
                    sDrawAll(temp);
                }
            }
        }
    }
    
}

void Engine::sSpeed()
{
    for (size_t i = 0; i != _componentsManager.getSpeedComponents().size(); i++) {
        if (_componentsManager.getSpeedComponents()[i]) {
            _componentsManager.getSpeedComponents()[i]->deccelerate();
        }
    }
}

void Engine::sCollision()
{
    for (size_t i = 0; i != _componentsManager.getCollisionsComponents()[0].size(); i++) {
        if (_componentsManager.getCollisionsComponents()[0][i]) {
            sf::IntRect r = _componentsManager.getGraphicalComponents()[i]->getHitbox();
            sf::Vector2f s = _componentsManager.getSpeedComponents()[i]->getSpeed();
            if (r.top + s.y <= 0) {
                _componentsManager.getSpeedComponents()[i]->setY(0 - r.top);
            }
            if (r.left + s.x <= 0) {
                _componentsManager.getSpeedComponents()[i]->setX(0 - r.left);
            }
            if (r.top + r.height + s.y >= 960) {
                _componentsManager.getSpeedComponents()[i]->setY(960 - (r.top + r.height));
            }
            if (r.left + r.width + s.x >= 1920) {
                _componentsManager.getSpeedComponents()[i]->setX(1920 - (r.left + r.width));
            }
        }
    }
}

void Engine::sPlayerFire()
{
    for (size_t i = 0; i != _componentsManager.getControllableComponents().size(); i++) {
        if (_componentsManager.getControllableComponents()[i]) {
            if (_componentsManager.getGraphicalComponents()[i]->isActualFrame(1)) {
                addEntityToGame(2);
                _componentsManager.getSpeedComponents()[_entitiesManager.getLastEntity() - 1]->setSpeed(20, 0);
                _componentsManager.getGraphicalComponents()[_entitiesManager.getLastEntity() - 1]->getSprite().setPosition(_componentsManager.getGraphicalComponents()[i]->getSprite().getPosition().x + 40, _componentsManager.getGraphicalComponents()[i]->getSprite().getPosition().y + 40);
            }
        }
    }
}

void Engine::sBehaviour()
{
    for (size_t i = 0; i != _componentsManager.getBehaviourComponents().size(); i++) {
        if (_componentsManager.getBehaviourComponents()[i]) {
            if (_componentsManager.getGraphicalComponents()[i]->getSprite().getPosition().x < 1500) {
                _componentsManager.getGraphicalComponents()[i]->changeAnimationLoop("attack");
                _componentsManager.getSpeedComponents()[i]->setSpeed(-20, 0);
            }
        }
    }

}

void Engine::handleNetworkCommand()
{
}

void Engine::removeEntity(size_t toRemove)
{
    if (_componentsManager.getBehaviourComponents()[toRemove])
        delete _componentsManager.getBehaviourComponents()[toRemove];
    if (_componentsManager.getSpeedComponents()[toRemove])
        delete _componentsManager.getSpeedComponents()[toRemove];
    if (_componentsManager.getGraphicalComponents()[toRemove])
        delete _componentsManager.getGraphicalComponents()[toRemove];
    if (_componentsManager.getCollisionsComponents()[0][toRemove])
        delete _componentsManager.getCollisionsComponents()[0][toRemove];
    if (_componentsManager.getCollisionsComponents()[1][toRemove])
        delete _componentsManager.getCollisionsComponents()[1][toRemove];
    if (_componentsManager.getCollisionsComponents()[2][toRemove])
        delete _componentsManager.getCollisionsComponents()[2][toRemove];
    if (_componentsManager.getSceneComponents()[toRemove])
        delete _componentsManager.getSceneComponents()[toRemove];
    if (_componentsManager.getBehaviourComponents()[toRemove])
        delete _componentsManager.getBehaviourComponents()[toRemove];
    if (_componentsManager.getTextComponents()[toRemove])
        delete _componentsManager.getTextComponents()[toRemove];
    if (_componentsManager.getControllableComponents()[toRemove])
        delete _componentsManager.getControllableComponents()[toRemove];
    
    _entitiesManager.removeEntity(toRemove);
}


void Engine::addToStringRegister(std::string key, std::string value)
{
    _strRegister[key] = value;
}

std::string Engine::getFromStringRegister(std::string key)
{
    return _strRegister[key];
}

void Engine::changeFromStringRegister(std::string key, std::string value)
{
    _strRegister[key] = value;
}

void Engine::concatValueToStringRegister(std::string key, std::string value)
{
    _strRegister[key] = _strRegister[key] + value;
}

bool Engine::run()
{
    

    // handleNetworkCommand();
    sSpeed();
    if (_queueReceive)
    if ((*_queueReceive).empty() == false) {
        RequestInfo temp;
        temp = (*_queueReceive).pop();
        if (temp._request == "MOVE") {
            sControl(temp);
        }
    }
    //sPlayerFire();
    // sBehaviour();
    // sCollision();
    return true;
}

void Engine::addToIntRegister(std::string str, int value)
{
    _intRegister[str] = value;
}

int Engine::getFromIntRegister(std::string str)
{
    return _intRegister.at(str);
}

void Engine::changeFromIntRegister(std::string str, int value)
{
    _intRegister[str] = value;
}

void Engine::increaseValueFromIntRegister(std::string str, int value)
{
    _intRegister[str] += value;
}

void Engine::sDrawAll(RequestInfo temp)
{
    RequestInfo tempToSend;
    std::size_t index = std::stoi(temp._id);
    sf::Vector2f pos;

    if (index < _componentsManager.getGraphicalComponents().size()) {
        if (_componentsManager.getSceneComponents()[index]) {
            if (_componentsManager.getSpeedComponents()[index] && _componentsManager.getGraphicalComponents()[index]) {
                pos = _componentsManager.getSpeedComponents()[index]->getSpeed();
                tempToSend._request = "POS";
                tempToSend._id = temp._id;
                tempToSend._firstValue = std::to_string(pos.x);
                tempToSend._secondValue = std::to_string(pos.y);
                (*_queueSend).push(tempToSend);
                _componentsManager.getGraphicalComponents()[index]->getSprite().move(_componentsManager.getSpeedComponents()[index]->getSpeed());
            }
                _componentsManager.getGraphicalComponents()[index]->update();
            }
    }
}

void Engine::setQueue(SafeQueue<RequestInfo> *queueReceive)
{
    _queueReceive = queueReceive;
}