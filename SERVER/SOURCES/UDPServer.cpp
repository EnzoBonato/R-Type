/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** UDPServer
*/

#include "../INCLUDE/UDPServer.hpp"

UDPServer::UDPServer(boost::asio::io_service& io_service): _socket(io_service, udp::endpoint(udp::v4(), 8080)), _lobby(&_queue, &_queueToSend)
{
    _lobby.setStatus(LOBBY);
    receive();
}

UDPServer::~UDPServer()
{
}

// FUNCTION

void UDPServer::test()
{
}

void UDPServer::receive()
{
    _socket.async_receive_from(boost::asio::buffer(_buffer, MAX_LENGHT),
                _endpoint,
                boost::bind(&UDPServer::handleReceive,
                this, boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
}

void UDPServer::handleReceive(const boost::system::error_code& error, std::size_t bytes_received)
{
    if (!error || error == boost::asio::error::message_size)
    {
        recupMessage(_buffer, bytes_received);
        _queue.push(_requestInfo);
        _endpointQueue.push(_endpoint);
    }
    receive();
}

void UDPServer::send(boost::asio::ip::udp::endpoint endpoint, std::string request, std::string value1, std::string value2, std::string id)
{
    std::ostringstream archive_stream;
    boost::archive::binary_oarchive archive(archive_stream);
    _sendBuffer._request = _prot.sendProtocol(request, id, value1, value2);
    archive << _sendBuffer;
    boost::shared_ptr<std::string> message(new std::string(archive_stream.str()));

    _socket.async_send_to(boost::asio::buffer(*message), endpoint,
            boost::bind(&UDPServer::handleSend, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void UDPServer::handleSend(boost::shared_ptr<std::string> , const boost::system::error_code& , std::size_t )
{
}

void UDPServer::recupMessage(char *buffer, std::size_t bytes_received)
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
}

void UDPServer::run()
{
    RequestInfo _temp;

    while (1) {
        if (_lobby.getStatus() == LOBBY && _queue.empty() == false) {
            _temp = _queue.pop();
            if (_temp._request == "CONNECT") {
                ClientHandler player(_temp._id, _endpoint);
                _lobby.addPlayer(player);
                if (_lobby.getNumberPlayer() > 1) {
                    for (std::size_t cnt = 0; cnt < _lobby.getNumberPlayer(); cnt++) {
                        _temp._request = "PLAYABLE";
                        _temp._id = "SERVER";
                        _temp._firstValue = std::to_string(cnt);
                        _temp._secondValue = "0";
                        _queueToSend.push(_temp);
                    }
                    _lobby.setup(&_queueToSend, &_queue);
                }
            }
        }
        if (_lobby.getStatus() == PLAYING) {
            _lobby.run();
        }
    }
}

void UDPServer::sendLoop()
{
    RequestInfo _temp;

    while (1) {
        if (_queueToSend.empty() == false) {
            _temp = _queueToSend.pop();
            if (_temp._request == "ADD" || _temp._request == "START" || _temp._request == "DESTROY" || _temp._request == "POS") {
                for (std::size_t cnt = 0; cnt < _lobby.getNumberPlayer(); cnt++) {
                    send(_lobby.getPlayerByIndex(cnt).getEndpoint(), _temp._request, _temp._firstValue, _temp._secondValue, _temp._id);
                }
            }
            else
                send(_endpointQueue.pop(), _temp._request, _temp._firstValue, _temp._secondValue, _temp._id);
        }
    }
}