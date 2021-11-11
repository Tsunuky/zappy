/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** arg
*/

#ifndef ARG_HPP_
#define ARG_HPP_

#include <ctype.h>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <iostream>

namespace Zappy {

class Arg {
public:
    Arg(int ac, char **av);
    ~Arg();
public:
    int CheckArg();
    int GetPort() const;
    std::string GetName() const;
    std::string GetMachine() const;
private:
    int _ac;
    char **_av;
    int _port = -1;
    std::string _name;
    std::string _machine = "localhost";
};
}

#endif /* !ARG_HPP_ */
