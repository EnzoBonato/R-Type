/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** ClientHandler
*/

#ifndef CLIENTHANDLER_HPP_
#define CLIENTHANDLER_HPP_

// INCLUDE

#include <iostream>
#include <boost/asio.hpp>

// DEFINE

enum {
    CLI_MENU = 0,
    CLI_LOBBY_WAIT = 1,
    CLI_MENU_READY = 2,
    CLI_IN_GAME = 3,
};

// CLASS DEFINITION

class ClientHandler {

    public:

        ClientHandler() = default;
        ClientHandler(std::string id, boost::asio::ip::udp::endpoint endpoint);
        ~ClientHandler();

        // COPPLIEN

        ClientHandler(const ClientHandler &other) = default;
        ClientHandler &operator=(const ClientHandler &other) = default;

        // FUNCTION

        int getStatus();
        std::string getId();
        void setStatus(int status);
        boost::asio::ip::udp::endpoint getEndpoint();

    protected:
    private:

        int _status;
        std::string _id;
        std::string _lobby;
        boost::asio::ip::udp::endpoint _endpoint;

};

#endif /* !CLIENTHANDLER_HPP_ */
