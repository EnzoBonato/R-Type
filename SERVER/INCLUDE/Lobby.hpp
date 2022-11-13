/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** Lobby
*/

#ifndef LOBBY_HPP_
#define LOBBY_HPP_

// INCLUDE

#include "Engine.hpp"
#include "../INCLUDE/ClientHandler.hpp"
#include "../../TOOLS/INCLUDE/SafeQueue.hpp"
#include "../../TOOLS/INCLUDE/DataBuffer.hpp"

// DEFINE

enum {
    LOBBY = 0,
    PLAYING = 1,
    PAUSE = 2,
};

// CLASS DEFINITION

class Lobby {

    public:

        Lobby() = default;
        Lobby(SafeQueue<RequestInfo> *, SafeQueue<RequestInfo> *);
        ~Lobby();

        // COPPLIEN

        Lobby(const Lobby &other) = default;
        Lobby &operator=(const Lobby &other) = default;

        // FUNCTION

        std::string getId();
        void setStatus(int status);
        std::size_t getNumberPlayer();
        bool isPlayerHere(std::string id);
        void addPlayer(ClientHandler player);
        void removePlayer(ClientHandler player);
        int getStatus();
        void setup(SafeQueue<RequestInfo> *queueToSend, SafeQueue<RequestInfo> *queueReceive);
        void run();

        ClientHandler getPlayerByIndex(std::size_t index);

        // TEMPORARY FUNCTION (DEBUG)

        void displayListPlayer();

    protected:
    private:

    int _status;
    std::string _id;
    std::vector<ClientHandler> _playerList;

    SafeQueue<RequestInfo> *_queueToSend;
    SafeQueue<RequestInfo> *_queueReceive;
    Engine _engine;
};

#endif /* !LOBBY_HPP_ */
