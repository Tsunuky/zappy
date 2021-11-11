/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** main
*/

#include "Arg.hpp"
#include "Client.hpp"
#include "ZappyException.hpp"
#include <cstring>
#include <boost/exception/diagnostic_information.hpp>

int main(int ac, char **av)
{
    try {
        Zappy::Arg argument(ac, av);
        Zappy::Client *client;

        if (ac == 2 && std::string(av[1]).compare("-help") == 0) {
            std::cout << "USAGE: ./zappy_ai -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name of the team\n\tmachine\tis the name of the machine; localhost by default" << std::endl;
            return 0;
        }
        if (argument.CheckArg() != 0)
            return 84;
        client = new Zappy::Client(argument.GetPort(), argument.GetName(), argument.GetMachine());
        client->SetSocket();
        client->Connect();
    } catch(const std::exception &err) {
        std::clog << boost::current_exception_diagnostic_information() << std::endl;
        return 84;
    } catch(...) {
        std::clog << boost::current_exception_diagnostic_information() << std::endl;
        return 84;
    }
    return 0;
}