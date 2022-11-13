/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** UDPServer
*/

#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

// INCLUDE

#include <string>
#include <thread>
#include <iterator>
#include <iostream>
#include "Lobby.hpp"
#include "Engine.hpp"
#include "../../TOOLS/INCLUDE/Protocol.hpp"
#include <boost/asio.hpp>
#include "../../TOOLS/INCLUDE/DataBuffer.hpp"
#include "../../TOOLS/INCLUDE/SafeQueue.hpp"
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/thread.hpp>
#include "ClientHandler.hpp"
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/serialization.hpp>

// DEFINE

using boost::asio::ip::udp;

// CLASS DEFINITION

class UDPServer {

    public:

        UDPServer(boost::asio::io_service& io_service);
        ~UDPServer();

        // COPPLIEN

        UDPServer(const UDPServer &other) = default;
        UDPServer &operator=(const UDPServer &other) = default;

        // FUNCTION

        void test();
        void receive();
        void handleReceive(const boost::system::error_code& error, std::size_t);

        void send(boost::asio::ip::udp::endpoint endpoint, std::string request, std::string value1, std::string value2, std::string id);
        void handleSend(boost::shared_ptr<std::string> , const boost::system::error_code& , std::size_t );

        void recupMessage(char *buffer, std::size_t bytes_received);

        void run();

        void sendLoop();

    protected:
    private:

        // DATA MESSAGE

        char _buffer[MAX_LENGHT] = "";

        Protocol _prot;
        DataBuffer _sendBuffer;
        DataBuffer _receiveBuffer;

        RequestInfo _requestInfo;

        // COMMUNICATION

        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _endpoint;

        SafeQueue<RequestInfo> _queue;
        SafeQueue<RequestInfo> _queueToSend;
        SafeQueue<boost::asio::ip::udp::endpoint> _endpointQueue;
        
        // ENGINE

        Lobby _lobby;
        boost::thread *_thread;
};

#endif /* !UDPSERVER_HPP_ */
