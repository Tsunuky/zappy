/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** Map.hpp
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Sprite.hpp"

class Map {

public:
    Map() {};
    ~Map() = default;
public:
    void setVector(std::vector<std::tuple<std::pair<double, double>, sf::IntRect ,ressource>> map) {
        _map = map;
    };
    std::vector<std::tuple<std::pair<double, double>, sf::IntRect ,ressource>> getVector() {return _map;};
private:
    std::vector<std::tuple<std::pair<double, double>, sf::IntRect ,ressource>> _map;
};

#endif /* !MAP_HPP_ */
