/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Inventory
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <string>
#include <cstring>

namespace Zappy
{
    class Inventory {
        public:
            Inventory(int food);
            ~Inventory();
            void update_inventory(std::string inventory);
            int getFood() const;
            int getLinemate() const;
            int getDeraumere() const;
            int getSibur() const;
            int getMendiane() const;
            int getPhiras() const;
            int getThystame() const;
        private:
            int _food;
            int _linemate;
            int _deraumere;
            int _sibur;
            int _mendiane;
            int _phiras;
            int _thystame;
    };
}

#endif /* !INVENTORY_HPP_ */
