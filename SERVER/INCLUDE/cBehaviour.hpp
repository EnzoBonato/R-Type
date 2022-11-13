/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** cBehaviour
*/

#include "iComponent.hpp"

#pragma once

enum eBehaviour {
    NEAR_PLAYER,
};

class cBehaviour : public iComponent
{
public:
    cBehaviour();
    ~cBehaviour();
    std::string getNextMove();
    eComponentList getComponentType() override;
    iComponent *clone() override;
private:

};