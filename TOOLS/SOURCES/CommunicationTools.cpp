/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** CommunicationTools
*/

#include "../INCLUDE/CommunicationTools.hpp"

CommunicationTools::CommunicationTools(boost::asio::ip::udp::endpoint endpoint, boost::asio::io_service& io_service) : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8080))
{
    _ownEndpoint = endpoint;
}

CommunicationTools::CommunicationTools(boost::asio::io_service& io_service, std::string port, std::string ip) : _socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0))
{
    boost::asio::ip::udp::resolver resolver(io_service);
    boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), ip, port);
    boost::asio::ip::udp::resolver::iterator itr = resolver.resolve(query);
    _ownEndpoint = *itr;
}

CommunicationTools::~CommunicationTools()
{
}

// FUNCTION

void CommunicationTools::receive()
{
    _socket.async_receive_from(boost::asio::buffer(_buffer, MAX_LENGHT), _ownEndpoint, boost::bind(&CommunicationTools::handleReceive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

ReqInfo CommunicationTools::handleReceive(const boost::system::error_code& error, std::size_t bytes_received)
{
    ReqInfo _data;
    DataBuf _receiveData;

    // CHECK IF ERROR

    if (!error || error == boost::asio::error::message_size)
    {
        _data._error = false;

        // CREATE ARCHIVE

        std::string buf(_buffer, bytes_received);
        std::istringstream archive_stream(buf);
        boost::archive::binary_iarchive archive(archive_stream);
        archive >> _receiveData;

        // FILL DATA

        _receiveData._request = _prot.receiveProtocol(_receiveData._request);
        _data._request = _prot.getStrFromProtocol(_receiveData._request, "REQUEST");
        _data._id = _prot.getStrFromProtocol(_receiveData._request, "ID");
        _data._firstValue = _prot.getStrFromProtocol(_receiveData._request, "VALUE_1");
        _data._secondValue = _prot.getStrFromProtocol(_receiveData._request, "VALUE_2");
    }
    else
        _data._error = true;
    return (_data);
}

void CommunicationTools::send(boost::asio::ip::udp::endpoint endpoint, std::string request, std::string msg, std::string id)
{
    DataBuf _sendData;

    // CREATE ARCHIVE

    std::ostringstream archive_stream;
    boost::archive::binary_oarchive archive(archive_stream);

    // USE PROTOCOL AND FILL ARCHIVE

    _sendData._request = _prot.sendProtocol(request, id, msg);
    archive << _sendData;

    boost::shared_ptr<std::string> message(new std::string(archive_stream.str()));

    // SEND

    _socket.async_send_to(boost::asio::buffer(*message), endpoint,
            boost::bind(&CommunicationTools::handleSend, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void CommunicationTools::handleSend(boost::shared_ptr<std::string> , const boost::system::error_code& , std::size_t)
{
}