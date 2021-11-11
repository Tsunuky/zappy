/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** System.hpp
*/
#include <thread>
#include <chrono>
#include <ctime>

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

class Chrono {

public:
    Chrono (int time = 300): _time(time) {};
    virtual ~Chrono() = default;
    void run() {
        while(_time > 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            _time--;
        }
    };
    int getTime() {return _time;};
private:
    int _time;
};

#endif