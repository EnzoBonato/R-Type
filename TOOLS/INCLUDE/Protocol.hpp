/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud [WSL: Ubuntu]
** File description:
** Protocol
*/

#ifndef PROTOCOL_HPP_
#define PROTOCOL_HPP_

// INCLUDE

#include <string>
#include <bitset>
#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <stdarg.h>
#include <math.h>

// DEFINE

// CLASS

class Protocol {

    public:

        Protocol();
        ~Protocol();

        // COPPLIEN

        Protocol(const Protocol &other) = default;
        Protocol &operator=(const Protocol &other) = default;

        // PROTOCOL FUNCTION

        std::string sendProtocol(std::string request, std::string id, std::string value1);
        std::string sendProtocol(std::string request, std::string id, std::string value1, std::string value2);
        std::string receiveProtocol(std::string hashedProtocol);
        std::string getStrFromProtocol(std::string protocol, std::string const tag);

    protected:
    private:

        // VARIABLE

        size_t _parsing;

        // CONVERTION FUNCTION

        std::string convertTxtToBin(std::string const str);
        std::string convertBinToHex(std::string const bin);
        std::string convertHexaToTxt(std::string const hexa);

        // REQUEST FUNCTION

        std::string unhashPartOfProtocol(std::string hashed);
};

#endif /* !PROTOCOL_HPP_ */