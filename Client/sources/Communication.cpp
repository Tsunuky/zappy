/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Communication
*/

#include "Communication.hpp"
#include <csignal>

Zappy::Communication::Communication(int fd, Zappy::Queue &commands, Zappy::Queue &responses) : _fdServer(fd), _commands(commands), _responses(responses)
{
}

Zappy::Communication::~Communication()
{
}

int Zappy::Communication::start()
{
    int rsp_cpt = 0;
    char buffer[4096];
    std::string nextRep;
    std::string lastRep;
    int byteRead = 0;
    fd_set toread;
    fcntl(_fdServer, F_SETFL, O_NONBLOCK);

    FD_ZERO(&_readfds);
    FD_SET(_fdServer, &_readfds);
    FD_SET(0, &_readfds);

    std::signal(SIGINT, []([[gnu::unused]]const int sig) {
        std::exit(0);
    });

    while (true) {
        memcpy(&toread, &_readfds, sizeof(toread));
        memset(buffer, 0, 4096);
        select(_fdServer + 1, &toread, NULL, NULL, NULL);
        if ((byteRead = recv(_fdServer, buffer, 4096, 0)) > 0) {
            for (int i = 0; i<byteRead; i++) {
                char c = buffer[i];
                if (c == '\n') {
                    if (nextRep.length() > 0) {
                        nextRep += c;
                        std::cout << nextRep;
                        _responses.push(nextRep);
                        rsp_cpt++;
                        lastRep = nextRep;
                        nextRep = "";
                    }
                } else nextRep += c;
            }
            if (lastRep.compare("dead\n") == 0) {
                std::cout << "EXIT" << std::endl;
                break;
            }
        }
        if (!_commands.isEmpty() && rsp_cpt > 0) {
            std::string instruction;
            _commands.pop(instruction);
            std::cout << instruction;
            send(_fdServer, instruction.c_str(), instruction.length(), 0);
        }
        /* if (FD_ISSET(_fdServer, &_readfds)) {
            recv(_fdServer, buffer, 4096, 0);
            str = buffer;
            std::cout << str;
            _responses.push(str);
            rsp_cpt++;
        } else
            continue; */
    }
    return 0;
}

int Zappy::Communication::launchCommunication(int fd, Zappy::Queue &commands, Zappy::Queue &responses)
{
    Zappy::Communication communication(fd, commands, responses);

    return communication.start();
}