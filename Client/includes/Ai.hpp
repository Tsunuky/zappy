/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Ai
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "Inventory.hpp"
#include "Queue.hpp"
#include <string>
#include <utility>
#include <vector>

namespace Zappy
{
    class Ai {
        public:
            Ai(Zappy::Queue &commands, Zappy::Queue &responses);
            ~Ai();
            int start();
            void foreward();
            void rigth();
            void left();
            void look();
            void checkInventory();
            void broadcastText();
            void connectNbr();
            void fork();
            void eject();
            void takeObject(std::string);
            void setObject(std::string);
            void incantation();
            void lookParsing(std::vector<std::string>);
            int getResponses();
            static int launchAi(Zappy::Queue &commands, Zappy::Queue &responses);
        private:
            Zappy::Queue &_commands;
            Zappy::Queue &_responses;
            std::pair<unsigned, unsigned> _mapSize;
            std::vector<std::pair<std::pair<int, int>, std::string>> _cache; // vector de pair coordonnée (x,y) et item
            int _life_unit = 1260;
            Zappy::Inventory *_inventory;
            bool _canFork = false;
            int _level = 1;
    };
}

#endif /* !AI_HPP_ */