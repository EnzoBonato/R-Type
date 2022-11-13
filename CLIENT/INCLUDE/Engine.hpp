    /*
** EPITECH PROJECT, 2022
** source
** File description:
** Engine
*/

#include "ComponentsManager.hpp"
#include "EntityManager.hpp"
#include "../../TOOLS/INCLUDE/SafeQueue.hpp"
#include "../../TOOLS/INCLUDE/DataBuffer.hpp"

#pragma once

enum {
    PLAYER = 1,
    TEAR = 2,
    BACKGROUND = 3,
    FOG = 4,
    MENU = 5,
    CHARGER_ENEMIES = 6,
    WAVE = 7,
    BOSS = 8,
    LIFEBAR_BLACK = 9,
    LIFEBAR_RED = 10,
    SKULL = 11,
    OTHER_PLAYER = 12
};

class Engine {
    public:

        Engine(SafeQueue<RequestInfo> *queueReceive, SafeQueue<RequestInfo> *queueSend);
        ~Engine();
        
        size_t addEntityToGame(size_t entity);
        size_t addEntityToGame(size_t entity, sf::Vector2f pos);
        void check();
        void mainLoop();
        void sDrawAll();
        void sControl();
        void sSpeed();
        void sLifeBar();
        void sCollision();
        void sPlayerFire();
        void waves();
        void summon_ennemies(int, int, bool);
        void sMenuing();
        void sBehaviour();
        void sUpdateMenu(sf::Event t);
        void handleNetworkCommand();
        void removeEntity(size_t r);

        void addToIntRegister(std::string key, int value);
        int getFromIntRegister(std::string key);
        void changeFromIntRegister(std::string key, int value);
        void increaseValueFromIntRegister(std::string key, int value);

        void addToStringRegister(std::string key, std::string value);
        std::string getFromStringRegister(std::string key);
        void changeFromStringRegister(std::string key, std::string value);
        void concatValueToStringRegister(std::string key, std::string value);
        
        bool run();
        void connectToLobby();

    private:
        EntityManager _entitiesManager;
        ComponentsManager _componentsManager;
        sf::RenderWindow *_window;
        eGameScene _scene = MENU_SCENE;
        
        std::map<std::string, int> _intRegister;
        std::map<std::string, std::string> _strRegister;

        sf::Event _event;
        sf::Font font;
        sf::Text t;

        
        int _indexPlayer;
        int _menuState = 0;
        sf::Vector2f _offset;

        SafeQueue<RequestInfo> *_queueSend;
        SafeQueue<RequestInfo> *_queueReceive;

        sf::Time elapsed_time;
        sf::Clock clock;

        bool _isWindowOnFocus;
};
