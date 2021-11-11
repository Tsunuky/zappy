/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** Queue
*/

#include "Queue.hpp"

Zappy::Queue::Queue()
{
}

Zappy::Queue::~Queue()
{
}

void Zappy::Queue::push(const std::string &elem) {
    std::unique_lock<std::mutex> lock(_mutex);
    _vals.push(elem);
}

void Zappy::Queue::pop(std::string &elem) {
    std::unique_lock<std::mutex> lock(_mutex);
    elem = _vals.front();
    _vals.pop();
}

bool Zappy::Queue::isEmpty(void) {
    std::unique_lock<std::mutex> lock(_mutex);
    return _vals.empty();
}

int Zappy::Queue::size(void) {
    std::unique_lock<std::mutex> lock(_mutex);
    return _vals.size();
}