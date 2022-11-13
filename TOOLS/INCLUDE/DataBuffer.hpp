/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud
** File description:
** DataBuffer
*/

#ifndef DATABUFFER_HPP_
#define DATABUFFER_HPP_

// INCLUDE

#include <string.h>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>

// DEFINE

#define MAX_LENGHT 1000000

// STRUCT DEFINITION

enum {

    // SERVER

    CONNECT = 100,
    DISCONNECT = 101,
    KO = 102,
    OK = 103,

    // LOBBY

    JOIN = 200,
    QUIT = 201,
    CREATE = 202,
    START = 203,

    // GAME

    LEFT = 300,
    UP = 301,
    RIGHT = 302,
    DOWN = 303,
    DESTROY = 304,
};

struct DataBuffer
{
    std::string _request;

    template<typename archive> void serialize(archive& _archive, const unsigned /*version*/) {
        _archive &_request;
    }
};

struct RequestInfo {
    std::string _request;
    std::string _id;
    std::string _firstValue;
    std::string _secondValue;
};

#endif /* !DATABUFFER_HPP_ */
