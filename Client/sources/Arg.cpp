/*
** EPITECH PROJECT, 2020
** tek2
** File description:
** Arg
*/

#include "Arg.hpp"

Zappy::Arg::Arg(int ac, char **av) : _ac(ac), _av(av)
{
}

Zappy::Arg::~Arg()
{
}

int Zappy::Arg::CheckArg()
{
    char c = 0;

    while ((c = getopt(_ac, _av, "p:n:h:")) != -1) {
        switch (c) {
            case 'p':
                _port = atoi(optarg);
                break;
            case 'n':
                _name = optarg;
                break;
            case 'h':
                _machine = optarg;
                break;
            case '?':
                return 84;
                break;
            default:
                return 84;
        }
    }
    if (optind < _ac)
        return 84;
    if ((_port > 0 && _port <= 65535) && !_name.empty()) {
        return 0;
    }
    std::cerr << "wrong argument, try -help option" << std::endl;
    return 84;
}

int Zappy::Arg::GetPort() const
{
    return _port;
}

std::string Zappy::Arg::GetName() const
{
    return _name;
}

std::string Zappy::Arg::GetMachine() const
{
    return _machine;
}