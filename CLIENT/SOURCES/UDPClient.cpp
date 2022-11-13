/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** UDPClient
*/

#include "../INCLUDE/UDPClient.hpp"

UDPClient::UDPClient(boost::asio::io_service& io_service, std::string idPlayer) : _socket(io_service, udp::endpoint(udp::v4(), 0))
{
    // SETUP ENDPOINT

    boost::asio::ip::udp::resolver resolver(io_service);
    boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), "127.0.0.1", "8080");
    boost::asio::ip::udp::resolver::iterator itr = resolver.resolve(query);
    _endpoint = *itr;
    _idPlayer = idPlayer;
    receive();
    
}

UDPClient::~UDPClient()
{
}

// FUNCTION

void UDPClient::receive()
{
    _socket.async_receive_from(boost::asio::buffer(_buffer, MAX_LENGHT),
                _endpoint, boost::bind(&UDPClient::handleReceive,
                this, boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
}

void UDPClient::handleReceive(const boost::system::error_code& error, std::size_t bytes_received)
{
    if (!error || error == boost::asio::error::message_size)
    {
        recupMessage(_buffer, bytes_received);
    }
    receive();
}

void UDPClient::send(std::string request, std::string value1, std::string value2, std::string id)
{
    _sendBuffer._request = _prot.sendProtocol(request, id, value1, value2);
    std::ostringstream archive_stream;
    boost::archive::binary_oarchive archive(archive_stream);

    archive << _sendBuffer;
    boost::shared_ptr<std::string> message(new std::string(archive_stream.str()));

    _socket.async_send_to(boost::asio::buffer(*message), _endpoint,
            boost::bind(&UDPClient::handleSend, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void UDPClient::handleSend(boost::shared_ptr<std::string> , const boost::system::error_code& , std::size_t )
{
}

void UDPClient::recupMessage(char *buffer, std::size_t bytes_received)
{
    std::string buf(buffer, bytes_received);
    std::istringstream archive_stream(buf);
    boost::archive::binary_iarchive archive(archive_stream);
    archive >> _receiveBuffer;
    _receiveBuffer._request = _prot.receiveProtocol(_receiveBuffer._request);
    _requestInfo._request = _prot.getStrFromProtocol(_receiveBuffer._request, "REQUEST");
    _requestInfo._id = _prot.getStrFromProtocol(_receiveBuffer._request, "ID");
    _requestInfo._firstValue = _prot.getStrFromProtocol(_receiveBuffer._request, "VALUE_1");
    _requestInfo._secondValue = _prot.getStrFromProtocol(_receiveBuffer._request, "VALUE_2");
    
    _queue.push(_requestInfo);
}

void UDPClient::game()
{
    Engine _engine(&_queue, &_queueToSend);
    
    _engine.addEntityToGame(BACKGROUND);
    _engine.addEntityToGame(FOG);
    _engine.addEntityToGame(MENU);
    _engine.addEntityToGame(WAVE);
    while (_engine.run());
}

void UDPClient::gameSend()
{
    RequestInfo temp;

    while (1) {
        if (_queueToSend.empty() == false) {
            temp = _queueToSend.pop();
            if (temp._id.empty() == true)
                temp._id = _idPlayer;
            send(temp._request, temp._firstValue, temp._secondValue, temp._id);         
        }
    }
}
