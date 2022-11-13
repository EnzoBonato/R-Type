/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** main
*/

#include "../INCLUDE/UDPClient.hpp"

void myThreadSend(UDPClient *client)
{
	client->game();
}

void myThreadGetRequest(UDPClient *client)
{
	client->gameSend();
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Retry with: ./r_type-client [Username]" << std::endl;
		return (84);
	}
	srand (time(NULL));
	try {

		boost::asio::io_service io_service;
		UDPClient client(io_service, av[1]);
		boost::thread _thread2(&myThreadSend, &client);
		boost::thread _thread3(&myThreadGetRequest, &client);

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