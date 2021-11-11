/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Sprite
*/

#include "Sprite.hpp"

void Sprite::setPosition(sf::Vector2f pos)
{
    _sprite.setPosition(pos.x, pos.y);
}

void Sprite::setOrigin(sf::Vector2f pos)
{
    _sprite.setPosition(pos.x, pos.y);
}

void Sprite::setRect(sf::IntRect rect)
{
    _sprite.setTextureRect(rect);
}

void Sprite::setRoatation(float rotate)
{
    _sprite.setRotation(rotate);
}

void Sprite::setTexture(const std::string &path, sf::IntRect area)
{
    _texture.loadFromFile(path, area);
    _sprite.setTexture(_texture);
}

void Sprite::setVisible(bool visible)
{
    _visible = visible;
}

void Sprite::setScale(sf::Vector2f scale)
{
    _sprite.setScale(scale.x, scale.y);
}

void Sprite::isMoving()
{

}

void Sprite::setMoving(bool moving)
{
    (void) moving;
}

/*void Sprite::createTexture(const std::string &path, sf::IntRect rect)
{
    _texture->loadFromFile(path, rect) == false
}*/