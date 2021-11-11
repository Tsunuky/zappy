/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Communication
*/

#ifndef COMMUNICATION_HPP_
#define COMMUNICATION_HPP_

#include "Queue.hpp"
#include <string>
#include <cstring>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

namespace Zappy
{
    class Communication {
        public:
            Communication(int fd, Zappy::Queue &commands, Zappy::Queue &responses);
            ~Communication();
            int start();
            static int launchCommunication(int fd, Zappy::Queue &commands, Zappy::Queue &responses);
        private:
            int _fdServer;
            fd_set _readfds;
            Zappy::Queue &_commands;
            Zappy::Queue &_responses;
    };
}
#endif /* !COMMUNICATION_HPP_ */
