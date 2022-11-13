/*
** EPITECH PROJECT, 2022
** B-CPP-500-NAN-5-1-rtype-ismael.brossaud [WSL: Ubuntu]
** File description:
** Protocol
*/

#include "../INCLUDE/Protocol.hpp"

Protocol::Protocol()
{
}

Protocol::~Protocol()
{
}

// STRING TO BINARY
std::string Protocol::convertTxtToBin(std::string const str)
{
    std::string bin = "";
    for (char const &c: str) {
        bin += std::bitset<8>(c).to_string();
    }
    return bin;
}

// BINARY TO HEXADECIMAL
std::string Protocol::convertBinToHex(std::string const bin)
{
    std::string hexa;
    std::string tmp;

    for (size_t i = 0; i < bin.length(); i += 4)
    {
        tmp = bin.substr(i, 4);
        if (!tmp.compare("0000")) {
            hexa = hexa + "0";
        } else if (!tmp.compare("0001")) {
            hexa = hexa + "1";
        } else if (!tmp.compare("0010")) {
          hexa = hexa + "2";
        } else if (!tmp.compare("0011")) {
            hexa = hexa + "3";
        } else if (!tmp.compare("0100")) {
            hexa = hexa + "4";
        } else if (!tmp.compare("0101")) {
            hexa = hexa + "5";
        } else if (!tmp.compare("0110")) {
            hexa = hexa + "6";
        } else if (!tmp.compare("0111")) {
            hexa = hexa + "7";
        } else if (!tmp.compare("1000")) {
            hexa = hexa + "8";
        } else if (!tmp.compare("1001")) {
            hexa = hexa + "9";
        } else if (!tmp.compare("1010")) {
            hexa = hexa + "A";
        } else if (!tmp.compare("1011")) {
            hexa = hexa + "B";
        } else if (!tmp.compare("1100")) {
            hexa = hexa + "C";
        } else if (!tmp.compare("1101")) {
            hexa = hexa + "D";
        } else if (!tmp.compare("1110")) {
            hexa = hexa + "E";
        } else if (!tmp.compare("1111")) {
            hexa = hexa + "F";
        } else {
            continue;
        }
    }
    return hexa;
}

// HEXADECIMAL TO STRING
std::string Protocol::convertHexaToTxt(std::string const hexa)
{
    std::string str;
    std::string tmp;

    for (auto it = hexa.begin(); it != hexa.end(); it += 2) {
        tmp = std::string(&(*it), 2);
        str += std::stoi(tmp, nullptr, 16);
    }
    return str;
}

// GET THE PART OF PROTOCOL YOU NEED AND UNHASH IT
std::string Protocol::unhashPartOfProtocol(std::string hashed)
{
    std::string str;

    while (_parsing < hashed.length() && hashed[_parsing] != 'X') {
        str += hashed[_parsing];
        _parsing++;
    }
    _parsing++;
    str = convertHexaToTxt(str);
    return str;
}


// PUBLIC FUNCTIONS

std::string Protocol::sendProtocol(std::string request, std::string id, std::string value1)
{
    std::string toSend;
    std::string binRequest = convertTxtToBin(request);
    std::string binId = convertTxtToBin(id);
    std::string binValue1 = convertTxtToBin(value1);
    std::string hexaRequest = convertBinToHex(binRequest);
    std::string hexaId = convertBinToHex(binId);
    std::string hexaValue1 = convertBinToHex(binValue1);

    toSend += hexaRequest;
    toSend += "X";
    toSend += hexaId;
    toSend += "X";
    toSend += hexaValue1;
    return toSend;
}

std::string Protocol::sendProtocol(std::string request, std::string id, std::string value1, std::string value2)
{
    std::string toSend;
    std::string binRequest = convertTxtToBin(request);
    std::string binId = convertTxtToBin(id);
    std::string binValue1 = convertTxtToBin(value1);
    std::string binValue2 = convertTxtToBin(value2);
    std::string hexaRequest = convertBinToHex(binRequest);
    std::string hexaId = convertBinToHex(binId);
    std::string hexaValue1 = convertBinToHex(binValue1);
    std::string hexaValue2 = convertBinToHex(binValue2);

    toSend += hexaRequest;
    toSend += "X";
    toSend += hexaId;
    toSend += "X";
    toSend += hexaValue1;
    toSend += "X";
    toSend += hexaValue2;
    return toSend;
}

std::string Protocol::receiveProtocol(std::string hashedProtocol)
{
    std::string protocol;
    int sep = 0;

    _parsing = 0;
    for (size_t i = 0; i < hashedProtocol.length(); i++) {
        if (hashedProtocol[i] == 'X') {
            sep++;
        }
    }
    for (int i = 0; i < sep + 1; i++) {
        protocol += unhashPartOfProtocol(hashedProtocol);
        protocol.push_back(' ');
    }
    return protocol;
}

std::string Protocol::getStrFromProtocol(std::string protocol, std::string const tag)
{
    size_t i = 0;
    int sep = 0;
    std::string str;

    if (tag == "REQUEST") {
        while (i < protocol.length()) {
            if (protocol[i] != ' ') {
                str += protocol[i];
            } else {
                break;
            }
            i++;
        }
    } else if (tag == "ID") {
        while (i < protocol.length()) {
            if (protocol[i] == ' ') {
                i++;
                while (protocol[i] != ' ') {
                    str += protocol[i];
                    i++;
                }
                break;
            }
            i++;
        }
    } else if (tag == "VALUE_1") {
        while (i < protocol.length()) {
            if (protocol[i] == ' ') {
                i++;
                sep++;
            }
            if (sep == 2) {
                while (protocol[i] != ' ') {
                    str += protocol[i];
                    i++;
                }
                break;
            }
            i++;
        }
    } else if (tag == "VALUE_2") {
        while (i < protocol.length() - 1) {
            if (protocol[i] == ' ') {
                i++;
                sep++;
            }
            if (sep == 3) {
                while (protocol[i] != ' ') {
                    str += protocol[i];
                    i++;
                }
                break;
            }
            i++;
        }
    }
    return str;
}

// int main()
// {
//     Protocol yessai;
//     std::string hashed = yessai.sendProtocol("JOIN", "ID", "12");
//     std::string request = yessai.receiveProtocol(hashed);
//     std::string req = yessai.getStrFromProtocol(request, "REQUEST");
//     std::string id = yessai.getStrFromProtocol(request, "ID");
//     std::string value_1 = yessai.getStrFromProtocol(request, "VALUE_1");
//     std::string value_2 = yessai.getStrFromProtocol(request, "VALUE_2");

//     std::cout << hashed << std::endl;
//     std::cout << request << std::endl;
//     std::cout << req << std::endl;
//     std::cout << id << std::endl;
//     std::cout << value_1 << std::endl;
//     if (value_2 == "") {
//         std::cout << value_2 << std::endl;
//     }
//     return 0;
// }