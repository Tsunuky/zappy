/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** Obj.hpp
*/

#ifndef OBJ_HPP_
#define OBJ_HPP_

#include "include.hpp"
//name space a mettre

class IObject {

public:
    virtual ~IObject() = default;
    virtual void setPosition(sf::Vector2f pos) = 0;
    virtual void setOrigin(sf::Vector2f pos) = 0;
    virtual void setRoatation(float rotate) = 0;
    virtual void setRect(sf::IntRect rect) = 0;
    virtual void setTexture(const std::string &path, sf::IntRect rect) = 0;
    virtual void setVisible(bool visible) = 0;
    virtual void isMoving() = 0;
    virtual void setMoving(bool moving) = 0;
};

#endif