/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** ClientHandler
*/

#include "../INCLUDE/ClientHandler.hpp"

ClientHandler::ClientHandler(std::string id, boost::asio::ip::udp::endpoint endpoint)
{
    _id = id;
    _status = CLI_MENU;
    _endpoint = endpoint;
}

ClientHandler::~ClientHandler()
{
}

// FUNCTION

int ClientHandler::getStatus()
{
    return (_status);
}

std::string ClientHandler::getId()
{
    return (_id);
}

void ClientHandler::setStatus(int status)
{
    _status = status;
}

boost::asio::ip::udp::endpoint ClientHandler::getEndpoint()
{
    return (_endpoint);
}