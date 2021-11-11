/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** Zappy
*/

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <mutex>
#include <queue>

namespace Zappy
{
    class Queue {
        private :
            std::mutex _mutex;
            std::queue<std::string> _vals;
        public :
            Queue();
            ~Queue();
            void push(const std::string &elem);
            void pop(std::string &elem);
            bool isEmpty(void);
            int size(void);
    };
}

#endif