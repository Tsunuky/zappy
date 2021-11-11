/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** device.hpp
*/

#ifndef DEVICE_HPP_
#define DEVICE_HPP_

#include <regex>
#include "include.hpp"
#include "Map.hpp"
#include "Queue.hpp"

enum EVENT {
    QUIT = -1,
    NONE,
};

class device {

public:
    device(Zappy::Queue &responses): _responses(responses) {};
    ~device() = default;
public:
    void createWindow();
    void destroyWindow();
    void drawAll();
    void drawSprite(int id);
    void run();
    void init();
    EVENT event();
    void randomFloor();
    void initmap(std::pair<int, int> size);
    void parseRessource();
    void initcell(float X, float Y, ressource R);
public:
    void setResponse();
public:
    std::vector<class Sprite> &getContainer() {return _container;};
    sf::IntRect getRect(int x ,int y, float max_x, float max_y);
    sf::RenderWindow &getWindow() {return _window;};
private:
    Zappy::Queue &_responses;
    sf::RenderWindow _window;
    sf::Event _event{};
    std::vector<class Sprite> _container;
    double _scale_x;
    double _scale_y;
    int _X;
    int _Y;
    std::vector<std::string> _response;
    std::vector<std::regex> _regexes;
    std::vector<std::tuple<double, double, ressource>> _cellsContent;
    Map map;
};

#endif /* !DEVICE_HPP_ */
