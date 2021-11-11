/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Inventory
*/

#include "Inventory.hpp"
#include <regex>
#include <sstream>
#include <iostream>

Zappy::Inventory::Inventory(int food)
{
    _food = food;
}

Zappy::Inventory::~Inventory()
{
}

void Zappy::Inventory::update_inventory(std::string inventory)
{
    inventory = inventory.substr(1, inventory.size() - 2);
    std::vector<std::string> strs;
    std::stringstream ss(inventory);
    std::regex regex("([a-zA-Z]+) ([0-9]*)");
    std::smatch smatch;

    for (std::string chunk; std::getline(ss, chunk, ','); strs.push_back(chunk));
    for (unsigned cpt = 0; cpt < strs.size(); cpt++) {
        std::regex_search(strs[cpt], smatch, regex);

        std::string sname = smatch[1];
        std::string samount = smatch[2];
        std::uint32_t amount = std::strtol(samount.c_str(), nullptr, 10);

        std::transform(sname.begin(), sname.end(), sname.begin(), [](unsigned char c){ return std::tolower(c); });

        if (sname == "linemate")
            _linemate = amount;
        else if (sname == "deraumere")
            _deraumere = amount;
        else if (sname == "sibur")
            _sibur = amount;
        else if (sname == "mendiane")
            _mendiane = amount;
        else if (sname == "phiras")
            _phiras = amount;
        else if (sname == "thystame")
            _thystame = amount;
        else if (sname == "food")
            _food = amount;
    }
}

int Zappy::Inventory::getFood() const
{
    return _food;
}

int Zappy::Inventory::getLinemate() const
{
    return _linemate;
}

int Zappy::Inventory::getDeraumere() const
{
    return _deraumere;
}

int Zappy::Inventory::getSibur() const
{
    return _sibur;
}

int Zappy::Inventory::getMendiane() const
{
    return _mendiane;
}

int Zappy::Inventory::getPhiras() const
{
    return _phiras;
}

int Zappy::Inventory::getThystame() const
{
    return _thystame;
}
