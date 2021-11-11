/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>
#include <unistd.h>
#include <cstring>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/select.h>
#include <sys/types.h>

namespace Zappy {
    class Client {
        public:
            Client(int port, std::string teamName, std::string machine): _port(port), _teamName(teamName), _machine(machine) {};
            ~Client() {close(acc);};
            void Connect();
            void SetSocket();
        private:
            struct sockaddr_in my_addr;
            int acc;
            int _port;
            std::string _teamName;
            std::string _machine;

    };
}

#endif /* !CLIENT_HPP_ */
