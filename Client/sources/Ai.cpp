/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Ai
*/

#include "Ai.hpp"
#include <algorithm>
#include <regex>
#include <iostream>

Zappy::Ai::Ai(Zappy::Queue &commands, Zappy::Queue &responses) : _commands(commands), _responses(responses)
{
    _inventory = new Zappy::Inventory(1260);
}

Zappy::Ai::~Ai()
{
}

void Zappy::Ai::foreward()
{
    _commands.push("Forward\n");
}

void Zappy::Ai::rigth()
{
    _commands.push("Right\n");
}

void Zappy::Ai::left()
{
    _commands.push("Left\n");
}

void Zappy::Ai::look()
{
    _commands.push("Look\n");
}

void Zappy::Ai::checkInventory()
{
    _commands.push("Inventory\n");
}

void Zappy::Ai::broadcastText()
{
    _commands.push("Broadcast thanks to hinara!\n");
}

void Zappy::Ai::connectNbr()
{
    _commands.push("Connect_nbr\n");
}

void Zappy::Ai::fork()
{
    _commands.push("Fork\n");
}

void Zappy::Ai::eject()
{
    _commands.push("Eject\n");
}

void Zappy::Ai::takeObject(std::string object)
{
    _commands.push(std::string("Take ").append(object).append("\n"));
}

void Zappy::Ai::setObject(std::string object)
{
    _commands.push(std::string("Set ").append(object).append("\n"));
}

void Zappy::Ai::incantation()
{
    _commands.push("Incantation\n");
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void Zappy::Ai::lookParsing(std::vector<std::string> look)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < static_cast<int>(look.size()); i++) {
        std::vector<std::string> strs;
        std::stringstream ss(look.at(i));
        for (std::string chunk; std::getline(ss, chunk, ' '); strs.push_back(chunk));
        if (x == y && i != 0) {
            y++;
            x = y*-1;
        } else if (i != 0) {
            x++;
        }
        std::pair<int, int> coord = std::make_pair(x, y);
        for (int cpt = 0; cpt < static_cast<int>(strs.size()); cpt++) {
            std::pair<std::pair<int, int>, std::string> tmp = std::make_pair(coord, strs.at(cpt));
            _cache.push_back(tmp);
        }
    }
}

int Zappy::Ai::getResponses()
{
    std::string rep;
    if (!_responses.isEmpty()) {
        _responses.pop(rep);
        rep = rep.substr(0, rep.size()-1);
        if (rep.compare("ok") != 0 && rep.compare("ko")) {
            if (is_number(rep) && std::atoi(rep.c_str()) > 0)
                _canFork = true;
            else if (is_number(rep))
                _canFork = false;
            else if (rep.at(0) == '[') {
                std::string pattern("\\[(([a-zA-Z]+) ([0-9]*))(, ([a-zA-Z]+) ([0-9]*))*\\]");
                if (std::regex_match(rep, std::regex(pattern)))
                    _inventory->update_inventory(rep);
                else {
                    rep = rep.substr(1, rep.size() - 2);
                    std::vector<std::string> strs;
                    std::stringstream ss(rep);
                    for (std::string chunk; std::getline(ss, chunk, ','); strs.push_back(chunk));
                    lookParsing(strs);
                }
            } else if (rep.compare("dead") == 0) {
                return -1;
            } else {
                _level = std::atoi(rep.substr(34, rep.size() - 34).c_str()) +1;
            }
        }
    }
    return 0;
}

int Zappy::Ai::start()
{
    int ret = 0;
    std::string welcome;
    std::string clientNum;
    std::string mapSize;

    while (_responses.size() < 3);
    _responses.pop(welcome);
    _responses.pop(clientNum);
    _responses.pop(mapSize);
    if ((std::atoi(clientNum.c_str()) - 1) > 0)
        _canFork = true;
    std::pair<unsigned, unsigned> size = std::make_pair(std::atoi(mapSize.substr(0, mapSize.find_first_of(' ')).c_str()), std::atoi(mapSize.substr(mapSize.find_first_of(' ') + 1, mapSize.size() - (mapSize.find_first_of(' ') + 1)).c_str()));
    _mapSize = size;
    while (ret == 0) {
        ret = getResponses();
        // insert algo here 
    }
    return 0;
}

int Zappy::Ai::launchAi(Zappy::Queue &commands, Zappy::Queue &responses)
{
    Zappy::Ai ai(commands, responses);

    return ai.start();
}
