/*
** EPITECH PROJECT, 2022
** source
** File description:
** Engine
*/

#include "../INCLUDE/Engine.hpp"

Engine::Engine(SafeQueue<RequestInfo> *queueReceive, SafeQueue<RequestInfo> *queueSend)
{
    _isWindowOnFocus = true;
     _queueSend = queueSend;
     _queueReceive = queueReceive;
    _window = new sf::RenderWindow(sf::VideoMode(1920, 960), "rType");
    _window->setFramerateLimit(60);
    _offset = {0, 0};
    addToIntRegister("MENU", 0);
    addToIntRegister("MENU_BIS", 0);
    addToIntRegister("OFFS_X", 0);
    addToIntRegister("OFFS_Y", 0);
    addToIntRegister("ROUND_NB", 1);
    addToIntRegister("ANIMATION_ROUND", 1);
    addToIntRegister("IS_BOSS", 0);
    addToIntRegister("IS_BOSS_ROUND", 0);
    addToIntRegister("PLAYER1", -1);
    addToIntRegister("PLAYER2", -1);
    addToIntRegister("PLAYER3", -1);
    addToIntRegister("PLAYER4", -1);

    _menuState = GAME_SCENE;
    _menuState = GAME_SCENE;
    font.loadFromFile("assets/font2.ttf");
    t.setFont(font);
    t.setFillColor(sf::Color::Green);
    t.setCharacterSize(21);
}

Engine::~Engine()
{
    
}

size_t Engine::addEntityToGame(size_t entity)
{
    this->_entitiesManager.addEntity(entity);
    size_t s = _entitiesManager.getFreePlace();
    this->_componentsManager.addEntity(entity, s);
    return s;
}

size_t Engine::addEntityToGame(size_t entity, sf::Vector2f pos)
{
    this->_entitiesManager.addEntity(entity);
    size_t s = _entitiesManager.getFreePlace();
    this->_componentsManager.addEntity(entity, s, pos);
    return s;
}


void Engine::check()
{
    _componentsManager.check();
}

void Engine::sControl()
{
    if (_isWindowOnFocus == false)
        return;
    for (size_t i = 0; i != _componentsManager.getControllableComponents().size(); i++) {
        if (_componentsManager.getControllableComponents()[i]) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                std::cout << "ID = " << i << std::endl;
                RequestInfo temp;
                temp._request = "MOVE";
                temp._id = std::to_string(i);
                temp._firstValue = "DOWN";
                temp._secondValue = "0";
                (*_queueSend).push(temp);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                RequestInfo temp2;
                temp2._request = "MOVE";
                temp2._id = std::to_string(i);
                temp2._firstValue = "UP";
                temp2._secondValue = "0";
                (*_queueSend).push(temp2);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                RequestInfo temp3;
                temp3._request = "MOVE";
                temp3._id = std::to_string(i);
                temp3._firstValue = "LEFT";
                temp3._secondValue = "0";
                (*_queueSend).push(temp3);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                RequestInfo temp4;
                temp4._request = "MOVE";
                temp4._id = std::to_string(i);
                temp4._firstValue = "RIGHT";
                temp4._secondValue = "0";
                (*_queueSend).push(temp4);
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
    for (size_t i = 0; i != _componentsManager.getCollisionsComponents().size(); i++) {
        if (_componentsManager.getCollisionsComponents()[i]) {
            if (_componentsManager.getCollisionsComponents()[i]->getCollisionType() == eCollisionType::collision1) {
                sf::IntRect r = _componentsManager.getGraphicalComponents()[i]->getHitbox();
                sf::Vector2f s = _componentsManager.getSpeedComponents()[i]->getSpeed();
                if (r.top + s.y <= 0)
                    _componentsManager.getSpeedComponents()[i]->setY(0 - r.top);
                if (r.left + s.x <= 0)
                    _componentsManager.getSpeedComponents()[i]->setX(0 - r.left);
                if (r.top + r.height + s.y >= 960)
                    _componentsManager.getSpeedComponents()[i]->setY(960 - (r.top + r.height));
                if (r.left + r.width + s.x >= 1920)
                    _componentsManager.getSpeedComponents()[i]->setX(1920 - (r.left + r.width));
            }
        }
    }
    for (size_t i = 0; i != _componentsManager.getCollisionsComponents().size(); i++) {
        if (_componentsManager.getCollisionsComponents()[i]) {
            for (size_t j = 0; j != _componentsManager.getCollisionsComponents().size(); j++) {
                if (_componentsManager.getCollisionsComponents()[j]) {
                    if (_componentsManager.getCollisionsComponents()[i]->getCollisionType() == collision2 && _componentsManager.getCollisionsComponents()[j]->getCollisionType() == collision3) {
                        if (_componentsManager.getGraphicalComponents()[i]->getHitbox().intersects(_componentsManager.getGraphicalComponents()[j]->getHitbox()) || _componentsManager.getGraphicalComponents()[j]->getHitbox().intersects(_componentsManager.getGraphicalComponents()[i]->getHitbox())) {
                            _componentsManager.getCollisionsComponents()[i]->decreaseLife(_componentsManager.getCollisionsComponents()[j]->getBodyDamage());
                            _componentsManager.getCollisionsComponents()[j]->decreaseLife(_componentsManager.getCollisionsComponents()[i]->getBodyDamage());
                        }
                    }
                }
            }
        }
    }
    for (size_t i = 0; i != _componentsManager.getCollisionsComponents().size(); i++) {
        if (_componentsManager.getCollisionsComponents()[i] && _componentsManager.getGraphicalComponents()[i]) {
            if (_componentsManager.getCollisionsComponents()[i]->getCollisionType() != collision1) {
                if (_componentsManager.getGraphicalComponents()[i]->getSprite().getPosition().x < -100 || _componentsManager.getGraphicalComponents()[i]->getSprite().getPosition().x > 2100 || _componentsManager.getCollisionsComponents()[i]->getLife() <= 0) {
                   removeEntity(i);
                }
            }
        }
    }
}

void Engine::sPlayerFire()
{
    for (size_t i = 0; i != _componentsManager.getControllableComponents().size(); i++) {
        if (_componentsManager.getControllableComponents()[i]) {
            if (_componentsManager.getGraphicalComponents()[i]->isActualFrame(1)) {
                size_t s = addEntityToGame(2, sf::Vector2f(_componentsManager.getGraphicalComponents()[i]->getSprite().getPosition().x + 40, _componentsManager.getGraphicalComponents()[i]->getSprite().getPosition().y + 40));
                _componentsManager.getSpeedComponents()[s]->accelerate(_componentsManager.getSpeedComponents()[i]->getSpeed().x, _componentsManager.getSpeedComponents()[i]->getSpeed().y);
            }
        }
    }
}

void Engine::sMenuing()
{

    if (getFromIntRegister("MENU") == 1) // Settings
        _offset = {_offset.x + ((-500 - _offset.x) / 15), _offset.y + ((-1000 - _offset.y) / 15)};
    if (getFromIntRegister("MENU") == 0) // Main
        _offset = {_offset.x + ((0 - _offset.x) / 15), _offset.y + ((0 - _offset.y) / 15)};
    if (getFromIntRegister("MENU") == 2) // Rules
        _offset = {_offset.x + ((-1900 - _offset.x) / 15), _offset.y + ((-200 - _offset.y) / 15)};


    for (size_t i = 0; i != _componentsManager.getSceneComponents().size(); i++) {
        if (_componentsManager.getSceneComponents()[i]) {
            if (_componentsManager.getSceneComponents()[i]->getScene() == eGameScene::MENU_SCENE) {
                _componentsManager.getGraphicalComponents()[i]->getSprite().setPosition(0, 0);
                _componentsManager.getGraphicalComponents()[i]->getSprite().move(_offset);
                _window->draw(_componentsManager.getGraphicalComponents()[i]->getSprite());
                if (getFromIntRegister("MENU") == 0) {
                    _componentsManager.getTextComponents()[i]->getText().setString(">");
                    _componentsManager.getTextComponents()[i]->getText().setPosition(650, 350);
                    _componentsManager.getTextComponents()[i]->getText().move(-getFromIntRegister("MENU_BIS") * 10, getFromIntRegister("MENU_BIS") * 125);
                }
                if (getFromIntRegister("MENU") == 1) {
                    if (getFromIntRegister("MENU_BIS") == 0) {
                        _componentsManager.getTextComponents()[i]->getText().setString("<-");
                        _componentsManager.getTextComponents()[i]->getText().setPosition(1240, 1340);
                    }
                    if (getFromIntRegister("MENU_BIS") == 1) {
                        _componentsManager.getTextComponents()[i]->getText().setString(">");
                        _componentsManager.getTextComponents()[i]->getText().setPosition(1160, 1455);
                    }
                    if (getFromIntRegister("MENU_BIS") == 2) {
                        _componentsManager.getTextComponents()[i]->getText().setString(">");
                        _componentsManager.getTextComponents()[i]->getText().setPosition(1170, 1655);
                    }    
                    if (getFromIntRegister("MENU_BIS") == 3) {
                        _componentsManager.getTextComponents()[i]->getText().setString("->");
                        _componentsManager.getTextComponents()[i]->getText().setPosition(1360, 1790);
                    }
                }
                if (getFromIntRegister("MENU") == 2) {
                    _componentsManager.getTextComponents()[i]->getText().setString("<-");
                    _componentsManager.getTextComponents()[i]->getText().setPosition(750, 50);
                }
                _componentsManager.getTextComponents()[i]->getText().move(_offset);
                _window->draw(_componentsManager.getTextComponents()[i]->getText());
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

void Engine::sLifeBar()
{
    // for (size_t i = 0; i != _componentsManager.getShapeComponents().size(); i++) {
    //     if (_componentsManager.getShapeComponents()[i]) {
    //     }
    // }
}

void Engine::sUpdateMenu(sf::Event t)
{
    if (t.type == sf::Event::TextEntered) {

    }
    if (t.type == sf::Event::KeyReleased) {
        if (t.key.code == sf::Keyboard::Enter) {
            if (getFromIntRegister("MENU") == 0 && getFromIntRegister("MENU_BIS") == 0) {
               _scene = LOBBY_SCENE;
               RequestInfo temp;
               temp._request = "CONNECT";
               temp._firstValue = "";
               temp._secondValue = "";
               (*_queueSend).push(temp);
            }
            if (getFromIntRegister("MENU") == 0 && getFromIntRegister("MENU_BIS") == 1) {
                changeFromIntRegister("MENU", 1);
                changeFromIntRegister("MENU_BIS", 0);
                return;
            }
            if (getFromIntRegister("MENU") == 0 && getFromIntRegister("MENU_BIS") == 2) {
                changeFromIntRegister("MENU", 2);
                changeFromIntRegister("MENU_BIS", 0);
                return;
            }
            if (getFromIntRegister("MENU") == 1 && getFromIntRegister("MENU_BIS") == 0) {
                changeFromIntRegister("MENU", 0);
                changeFromIntRegister("MENU_BIS", 1);
                return;
            }
            if (getFromIntRegister("MENU") == 2 && getFromIntRegister("MENU_BIS") == 0) {
                changeFromIntRegister("MENU", 0);
                changeFromIntRegister("MENU_BIS", 2);
                return;
            }
        }
        if (getFromIntRegister("MENU") == 1) {
            if (t.key.code == sf::Keyboard::Up)
                increaseValueFromIntRegister("MENU_BIS", -1);
            if (t.key.code == sf::Keyboard::Down)
                increaseValueFromIntRegister("MENU_BIS", 1);
            if (getFromIntRegister("MENU_BIS") < 0)
                changeFromIntRegister("MENU_BIS", 3);
            if (getFromIntRegister("MENU_BIS") > 3)
                changeFromIntRegister("MENU_BIS", 0);
        }

        if (getFromIntRegister("MENU") == 0) {
            if (t.key.code == sf::Keyboard::Up)
                increaseValueFromIntRegister("MENU_BIS", -1);
            if (t.key.code == sf::Keyboard::Down)
                increaseValueFromIntRegister("MENU_BIS", 1);
            if (getFromIntRegister("MENU_BIS") < 0)
                changeFromIntRegister("MENU_BIS", 2);
            if (getFromIntRegister("MENU_BIS") > 2)
                changeFromIntRegister("MENU_BIS", 0);
        }
    }
}

void Engine::handleNetworkCommand()
{
}

void Engine::removeEntity(size_t toRemove)
{
    if (_componentsManager.getBehaviourComponents()[toRemove]) {
        delete _componentsManager.getBehaviourComponents()[toRemove];
        _componentsManager.getBehaviourComponents()[toRemove] = nullptr;
    }
    if (_componentsManager.getSpeedComponents()[toRemove]) {
        delete _componentsManager.getSpeedComponents()[toRemove];
        _componentsManager.getSpeedComponents()[toRemove] = nullptr;
    }
    if (_componentsManager.getGraphicalComponents()[toRemove]) {
        delete _componentsManager.getGraphicalComponents()[toRemove];
        _componentsManager.getGraphicalComponents()[toRemove] = nullptr;
    }
    if (_componentsManager.getCollisionsComponents()[toRemove]) {
        delete _componentsManager.getCollisionsComponents()[toRemove];
        _componentsManager.getCollisionsComponents()[toRemove] = nullptr;
    }
    if (_componentsManager.getSceneComponents()[toRemove]) {
        delete _componentsManager.getSceneComponents()[toRemove];
        _componentsManager.getSceneComponents()[toRemove] = nullptr;
    }
    if (_componentsManager.getBehaviourComponents()[toRemove]) {
        delete _componentsManager.getBehaviourComponents()[toRemove];
        _componentsManager.getBehaviourComponents()[toRemove] = nullptr;
    }
    if (_componentsManager.getTextComponents()[toRemove]) {
        delete _componentsManager.getTextComponents()[toRemove];
        _componentsManager.getTextComponents()[toRemove] = nullptr;
    }
    if (_componentsManager.getControllableComponents()[toRemove]) {
        delete _componentsManager.getControllableComponents()[toRemove];
        _componentsManager.getControllableComponents()[toRemove] = nullptr;
    }
    // if (_componentsManager.getShapeComponents()[toRemove]) {
    //     delete _componentsManager.getShapeComponents()[toRemove];
    //     _componentsManager.getShapeComponents()[toRemove] = nullptr;
    // }
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

void Engine::summon_ennemies(int entity, int nb_ennemies, bool is_boss)
{
    if (is_boss == false) {
        for (int i = 0; i != nb_ennemies; i++)
            addEntityToGame(entity, sf::Vector2f(2000 + rand() % 300 + 0, rand() % 800 + 100));
    } else
        addEntityToGame(entity, sf::Vector2f(1700, 200));
}

void Engine::waves()
{
    sf::Time delta_time = sf::seconds(3);
    elapsed_time += clock.restart();
    int nb_ennemies = rand() % 9 + 2;
    std::string buff = "Round ";
    
    while (elapsed_time >= delta_time) {
        if (getFromIntRegister("ANIMATION_ROUND") == 1) {
            if (getFromIntRegister("IS_BOSS") == 1) {
                changeFromIntRegister("IS_BOSS_ROUND", 1);
                summon_ennemies(8, 1, true);
            }
            else
                summon_ennemies(6, nb_ennemies, false);
            changeFromIntRegister("ANIMATION_ROUND", 0);
        } else {
            if (getFromIntRegister("IS_BOSS_ROUND") == 0) {
                increaseValueFromIntRegister("ROUND_NB", 1);
                if (getFromIntRegister("ROUND_NB") % 10 == 0)
                    changeFromIntRegister("IS_BOSS", 1);
                else
                    changeFromIntRegister("IS_BOSS", 0);
                changeFromIntRegister("ANIMATION_ROUND", 1);
            }
        }
        elapsed_time -= delta_time;
    }
    for (size_t i = 0; i != _componentsManager.getTextComponents().size(); i++) {
        if (_componentsManager.getTextComponents()[i] && _componentsManager.getSceneComponents()[i]) {
            if (_componentsManager.getSceneComponents()[i]->getScene() == eGameScene::GAME_SCENE) {
                if (getFromIntRegister("IS_BOSS") == 1)
                    buff = "BOSS !!!";
                else
                    buff += std::to_string(getFromIntRegister("ROUND_NB"));
                _componentsManager.getTextComponents()[i]->getText().setString(buff); 
            }
        }
    }
}

bool Engine::run()
{
    if (!_window->isOpen())
        return false;
    while (_window->pollEvent(_event)) {
        switch (_event.type) {
            case (sf::Event::Closed):
                _window->close();
                break;
            case (sf::Event::KeyReleased):
                if (_scene == MENU_SCENE)
                    sUpdateMenu(_event);
                break;
            case (sf::Event::LostFocus):
                _isWindowOnFocus = false;
                break;
            case (sf::Event::GainedFocus):
                _isWindowOnFocus = true;
                break;
            default:
                break;
        }
    }
    if (_scene == MENU_SCENE) {
        sMenuing();
    } else if (_scene == LOBBY_SCENE) {
        connectToLobby();
    } else if (_scene == GAME_SCENE) {
        if ((*_queueReceive).empty() == false) {
            RequestInfo temp;
            int index;
            sf::Vector2f pos;
            temp = (*_queueReceive).pop();
            index = std::stoi(temp._id);
            pos.x = std::stoi(temp._firstValue);
            pos.y = std::stoi(temp._secondValue);
            if (temp._request == "POS") {
                if(index < _componentsManager.getGraphicalComponents().size()) {
                    if (_componentsManager.getSceneComponents()[index]) {
                        if (_componentsManager.getSpeedComponents()[index] && _componentsManager.getGraphicalComponents()[index]) {
                            if (index != getFromIntRegister("PLAYER1") || index != getFromIntRegister("PLAYER3") || index != getFromIntRegister("PLAYER3") || index != getFromIntRegister("PLAYER4")) {
                                _componentsManager.getGraphicalComponents()[index]->getSprite().move(pos);
                            }
                        }
                    }
                }
            }
        }
        sControl();
        sDrawAll();
    }
    
    _window->display();
    _window->clear();
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

void Engine::sDrawAll()
{
    for (size_t i = 0; i != _componentsManager.getGraphicalComponents().size(); i++) {
        if (_componentsManager.getSceneComponents()[i]) {
            if (_componentsManager.getSceneComponents()[i]->getScene() == GAME_SCENE) {
                if (_componentsManager.getSpeedComponents()[i] && _componentsManager.getGraphicalComponents()[i]) {
                    if (i != getFromIntRegister("PLAYER1") || i != getFromIntRegister("PLAYER3") || i != getFromIntRegister("PLAYER3") || i != getFromIntRegister("PLAYER4"))
                    _componentsManager.getGraphicalComponents()[i]->getSprite().move(_componentsManager.getSpeedComponents()[i]->getSpeed());
                }
                // if (_componentsManager.getShapeComponents()[i] && getFromIntRegister("IS_BOSS_ROUND") == 1)
                // {
                //     std::cout << "passed\n";
                //     _window->draw(_componentsManager.getShapeComponents()[i]->getShape());
                // }
                if (_componentsManager.getTextComponents()[i] && getFromIntRegister("ANIMATION_ROUND") == 1)
                    _window->draw(_componentsManager.getTextComponents()[i]->getText());
                if (_componentsManager.getGraphicalComponents()[i] && _componentsManager.getCollisionsComponents()[i]) {
                    if (_componentsManager.getCollisionsComponents()[i]->isInvulnerable()) {
                        _componentsManager.getGraphicalComponents()[i]->getSprite().setColor(sf::Color(255, 255, 255, 100));
                    } else {
                        _componentsManager.getGraphicalComponents()[i]->getSprite().setColor(sf::Color(255, 255, 255, 255));
                    }
                }
                if (_componentsManager.getGraphicalComponents()[i]) {
                    _componentsManager.getGraphicalComponents()[i]->update();
                    _componentsManager.getGraphicalComponents()[i]->display(*_window);
                }
            }
        }
    }
}

void Engine::connectToLobby()
{
    RequestInfo temp;

    if ((*_queueReceive).empty() == false) {
        temp = (*_queueReceive).pop();
        if (temp._request == "PLAYABLE") {
            _indexPlayer = std::stoi(temp._firstValue) + 1;
        }
        if (temp._request == "ADD") {
            if (temp._id == "1") {
                if (std::stoi(temp._firstValue) == _indexPlayer) {
                    addEntityToGame(PLAYER);
                    std::string toRegister = "PLAYER";
                    toRegister.append(temp._firstValue);
                    changeFromIntRegister(toRegister, (_componentsManager.getGraphicalComponents().size() - 1));
                }
                else {
                    addEntityToGame(OTHER_PLAYER);
                    std::string toRegister = "PLAYER";
                    toRegister.append(temp._firstValue);
                    changeFromIntRegister(toRegister, (_componentsManager.getGraphicalComponents().size() - 1));
                }
                if (temp._secondValue == "LAST")
                    _scene = GAME_SCENE;
            }
            
        }
    }
}