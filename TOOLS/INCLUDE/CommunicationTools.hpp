/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** CommunicationTools
*/

#ifndef COMMUNICATIONTOOLS_HPP_
#define COMMUNICATIONTOOLS_HPP_

// INCLUDE

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/serialization.hpp>

// OWN INCLUDE

#include "Protocol.hpp"

// DEFINE

#define MAX_LENGHT 1000000

// STRUCT DEFINITION

struct DataBuf
{
    std::string _request;

    template<typename archive> void serialize(archive& _archive, const unsigned /*version*/) {
        _archive &_request;
    }
};

struct ReqInfo {
    bool _error;
    std::string _request;
    std::string _id;
    std::string _firstValue;
    std::string _secondValue;
};

// CLASS DEFINITION

class CommunicationTools {

    public:

        CommunicationTools() = default;
        CommunicationTools(boost::asio::ip::udp::endpoint endpoint, boost::asio::io_service& io_service);
        CommunicationTools(boost::asio::io_service& io_service, std::string port, std::string ip);
        ~CommunicationTools();

        // COPPLIEN

        CommunicationTools(const CommunicationTools &other) = default;
        CommunicationTools &operator=(const CommunicationTools &other) = default;

        // FUNCTION

        void receive();
        ReqInfo handleReceive(const boost::system::error_code& error, std::size_t);
        void handleSend(boost::shared_ptr<std::string> , const boost::system::error_code& , std::size_t);
        void send(boost::asio::ip::udp::endpoint endpoint, std::string _request, std::string _msg, std::string id);

    protected:
    private:

        // DATA

        char _buffer[MAX_LENGHT] = "";

        Protocol _prot;

        ReqInfo _requestInfo;

        // COMMUNICATION

        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _ownEndpoint;
};

#endif /* !COMMUNICATIONTOOLS_HPP_ */
