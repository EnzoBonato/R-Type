/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** main
*/

#include "../INCLUDE/UDPServer.hpp"

void myThreadLogic(UDPServer *server)
{
    server->run();
}

void myThreadSend(UDPServer *server)
{
    server->sendLoop();
}


int main(void)
{

    try
    {      
        boost::asio::io_service io_service;
        UDPServer server(io_service);

		boost::thread _thread2(&myThreadSend, &server);
		boost::thread _thread3(&myThreadLogic, &server);

        io_service.run();
		_thread2.join();
		_thread3.join();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}