/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** cScene
*/

#include "iComponent.hpp"

enum eGameScene {
    MENU_SCENE,
    GAME_SCENE,
    LOBBY_SCENE
};

#pragma once

class cScene  final: public iComponent
{
public:
    cScene(eGameScene e);
    eComponentList getComponentType() override;
    iComponent *clone() override;
    eGameScene getScene();
    void Destroy() { delete this; }
    ~cScene();
private:
    eGameScene _scene;
};
