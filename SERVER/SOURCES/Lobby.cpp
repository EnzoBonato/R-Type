/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** Lobby
*/

#include "../INCLUDE/Lobby.hpp"

Lobby::Lobby(SafeQueue<RequestInfo> *queueReceive, SafeQueue<RequestInfo> *queueToSend): _engine(queueReceive, queueToSend)
{
    _queueReceive = queueReceive;
    _queueToSend = _queueToSend;
    _engine.setQueue(_queueReceive);
    _id = "LOBBY";
    _status = LOBBY;
}

Lobby::~Lobby()
{
}

// FUNCTION

std::string Lobby::getId()
{
    return (_id);
}
void Lobby::setStatus(int status)
{
    _status = status;
}

std::size_t Lobby::getNumberPlayer()
{
    return (_playerList.size());
}

bool Lobby::isPlayerHere(std::string id)
{
    for (std::size_t cnt = 0; cnt < _playerList.size(); cnt++) {
        if (_playerList.at(cnt).getId() == id)
            return (true);
    }
    return false;
}

void Lobby::addPlayer(ClientHandler player)
{
    _playerList.push_back(player);
}

void Lobby::removePlayer(ClientHandler player)
{
    std::size_t index = -1;
    std::size_t myError = -1;

    for (std::size_t cnt = 0; cnt < _playerList.size(); cnt++) {
        if (_playerList.at(cnt).getId() == player.getId()) {
            index = cnt;
            (_playerList.at(cnt));
        }
    }
    if (index != myError)
        _playerList.erase(_playerList.begin() + index);
}

int Lobby::getStatus()
{
    return (_status);
}

void Lobby::setup(SafeQueue<RequestInfo> *queueToSend, SafeQueue<RequestInfo> *queueReceive)
{
    RequestInfo temp;

    temp._request = "ADD";
    temp._id = "1";
    temp._secondValue = "0";
    _queueToSend = queueToSend;
    _queueReceive = queueReceive;
    _engine.addEntityToGame(BACKGROUND);
    _engine.addEntityToGame(FOG);
    _engine.addEntityToGame(MENU);
    _engine.addEntityToGame(WAVE);
    for (std::size_t cnt = 0; cnt < getNumberPlayer(); cnt++) {
        temp._firstValue = std::to_string(cnt + 1);
        if (cnt == (getNumberPlayer() - 1)) {
            temp._secondValue = "LAST";
        }
        (*_queueToSend).push(temp);
        _engine.addEntityToGame(1);
    };
    setStatus(PLAYING);
}

void Lobby::run()
{
    _engine.run();
}

ClientHandler Lobby::getPlayerByIndex(std::size_t index)
{
    return (_playerList.at(index));
}

// TEMPORARY FUNCTION (DEBUG)

void Lobby::displayListPlayer()
{
    for (std::size_t count = 0; count < _playerList.size(); count++) {
        std::cout << _playerList.at(count).getId();
        std::cout << ": " << _playerList.at(count).getStatus() << std::endl;
    }
}