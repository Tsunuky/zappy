/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <memory>
#include "Obj.hpp"

typedef struct roofRect {
    sf::IntRect TopLeft;
    sf::IntRect TopMid;
    sf::IntRect TopRight;
    sf::IntRect MidLeft;
    sf::IntRect Mid;
    sf::IntRect MidRight;
    sf::IntRect DownLeft;
    sf::IntRect DownRight;
    sf::IntRect DownMid;
} roofRect;

typedef struct ressource {
    int R0;
    int R1;
    int R2;
    int R3;
    int R4;
    int R5;
    int R6;
} ressource;

// remettre le ccreate texture avec le rect pour le container;

class Sprite: public IObject {

public:
    Sprite() {};
    ~Sprite() {};
public:
    void setPosition(sf::Vector2f pos);
    void setRoatation(float rotate);
    void setScale(sf::Vector2f scale);
    void setOrigin(sf::Vector2f pos);
    void setTexture(const std::string &path, sf::IntRect area);
    void setRect(sf::IntRect rect);
    void setVisible(bool visible);
    void setMoving(bool moving);
public:
    sf::Sprite getSprite() {return _sprite;};
public:
    void isMoving();
public:
    roofRect roof;
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    bool _visible;
};

#endif /* !SFML_HPP_ */
