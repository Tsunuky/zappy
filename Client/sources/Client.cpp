/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Client
*/

#include "Client.hpp"
#include "Queue.hpp"
#include "Communication.hpp"
#include "Ai.hpp"
#include "device.hpp"
#include <thread>
#include <cstring>

void Zappy::Client::Connect()
{
    memset(&my_addr, 0, sizeof(struct sockaddr_in));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(_port);
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    acc = socket(AF_INET, SOCK_STREAM, 0);

    Zappy::Queue commands;
    Zappy::Queue responses;
    if (connect(acc, (struct sockaddr*)&my_addr, sizeof(my_addr)) != 0) { 
        printf("Connection with the server failed...\n"); 
        exit(0);
    }
    commands.push(_teamName.append("\n"));
    //commands.push("Look\n");
    std::thread communicationThread(Zappy::Communication::launchCommunication, acc, std::ref(commands), std::ref(responses));
    if (_teamName.compare("GRAPHIC\n") != 0) {
        std::thread aiThread(Zappy::Ai::launchAi, std::ref(commands), std::ref(responses));
        aiThread.join();
        communicationThread.join();
    } else {
        device game(std::ref(responses));

        game.setResponse();
        game.run();
        std::exit(0);
        communicationThread.join();
    }
}

void Zappy::Client::SetSocket()
{
}
