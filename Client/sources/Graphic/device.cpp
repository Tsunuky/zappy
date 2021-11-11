/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** main.cpp
*/

#include <boost/exception/diagnostic_information.hpp>
#include <vector>
#include <boost/functional/hash.hpp>
#include <cstdlib>

#include "ZappyException.hpp"
#include "device.hpp"

//

void GardenCord(roofRect &rect)
{
    rect.TopLeft = sf::IntRect(0, 0, 16, 16); //ok
    rect.TopMid = sf::IntRect(17, 0, 16, 16); //ok
    rect.TopRight = sf::IntRect(34, 0, 16, 16); //ok
    rect.MidLeft = sf::IntRect(0, 17, 16, 16); //ok
    rect.Mid = sf::IntRect(17, 17, 16, 16); //ok
    rect.MidRight = sf::IntRect(34,17, 16, 16); //ok
    rect.DownLeft = sf::IntRect(0, 34, 16, 16); //ok
    rect.DownMid = sf::IntRect(17, 34, 16, 16); //ok
    rect.DownRight = sf::IntRect(34, 34, 16, 16); //ok
}

void yellowCord(roofRect &rect)
{
    rect.TopLeft = sf::IntRect(0, 51, 16, 16);
    rect.TopMid = sf::IntRect(17, 51, 16, 16);
    rect.TopRight = sf::IntRect(34, 51, 16, 16);
    rect.MidLeft = sf::IntRect(0, 68, 16, 16);
    rect.Mid = sf::IntRect(17, 68, 16, 16);
    rect.MidRight = sf::IntRect(34, 68, 16, 16);
    rect.DownLeft = sf::IntRect(0, 85, 16, 16);
    rect.DownMid = sf::IntRect(17, 85, 16, 16);
    rect.DownRight = sf::IntRect(34, 85, 16, 16);
}

void factoryCord(roofRect &rect)
{
    rect.TopLeft = sf::IntRect(136, 0, 16, 16);
    rect.TopMid = sf::IntRect(153, 0, 16, 16);
    rect.TopRight = sf::IntRect(170, 0, 16, 16);
    rect.MidLeft = sf::IntRect(136, 17, 16, 16);
    rect.Mid = sf::IntRect(153, 17, 16, 16);
    rect.MidRight = sf::IntRect(170, 17, 16, 16);
    rect.DownLeft = sf::IntRect(136, 34, 16, 16);
    rect.DownMid = sf::IntRect(153, 34, 16, 16);
    rect.DownRight = sf::IntRect(170, 34, 16, 16);
}

void GreyCord(roofRect &rect)
{
    rect.TopLeft = sf::IntRect(136, 51, 16, 16);
    rect.TopMid = sf::IntRect(153, 51, 16, 16);
    rect.TopRight = sf::IntRect(170, 51, 16, 16);
    rect.MidLeft = sf::IntRect(136, 68, 16, 16);
    rect.Mid = sf::IntRect(153, 68, 16, 16);
    rect.MidRight = sf::IntRect(170, 68, 16, 16);
    rect.DownLeft = sf::IntRect(136, 85, 16, 16);
    rect.DownMid = sf::IntRect(153, 85, 16, 16);
    rect.DownRight = sf::IntRect(170, 85, 16, 16);
}

void RedCord(roofRect &rect)
{
    rect.TopLeft = sf::IntRect(289, 0, 16, 16);
    rect.TopMid = sf::IntRect(306, 0, 16, 16);
    rect.TopRight = sf::IntRect(323, 0, 16, 16);
    rect.MidLeft = sf::IntRect(289, 34, 16, 16);
    rect.Mid = sf::IntRect(306, 34, 16, 16);
    rect.MidRight = sf::IntRect(323, 34, 16, 16);
    rect.DownLeft = sf::IntRect(289, 51, 16, 16);
    rect.DownMid = sf::IntRect(306, 51, 16, 16);
    rect.DownRight = sf::IntRect(323, 51, 16, 16);
}

void OrangeCord(roofRect &rect)
{
    rect.TopLeft = sf::IntRect(289, 68, 16, 16);
    rect.TopMid = sf::IntRect(306, 68, 16, 16);
    rect.TopRight = sf::IntRect(323, 68, 16, 16);
    rect.MidLeft = sf::IntRect(289, 102, 16, 16);
    rect.Mid = sf::IntRect(306, 102, 16, 16);
    rect.MidRight = sf::IntRect(323, 102, 16, 16);
    rect.DownLeft = sf::IntRect(289, 119, 16, 16);
    rect.DownMid = sf::IntRect(306, 119, 16, 16);
    rect.DownRight = sf::IntRect(323, 119, 16, 16);
}

void device::randomFloor()
{
    int rand;
    getContainer().at(0).setTexture("./Assets/tilemap.png", sf::IntRect(0, 0, 458, 305));

    std::srand(std::time(nullptr));
    rand = std::rand() % 6;
    if (rand == 0)
        GardenCord(getContainer().at(0).roof);
    if (rand == 1)
        yellowCord(getContainer().at(0).roof);
    if (rand == 2)
        factoryCord(getContainer().at(0).roof);
    if (rand == 3)
        GreyCord(getContainer().at(0).roof);
    if (rand == 4)
        OrangeCord(getContainer().at(0).roof);
    if (rand == 5)
        RedCord(getContainer().at(0).roof);
}

//
void device::createWindow()
{
    _window.create(sf::VideoMode() , sf::String("Zappy"), sf::Style::Fullscreen);
}

void device::destroyWindow()
{
    _window.close();
};

void device::drawSprite(int id)
{
    for (auto &i : map.getVector()) {
        getContainer().at(id).setRect(std::get<1>(i));
        getContainer().at(id).setScale(sf::Vector2f(_scale_x, _scale_y));
        getContainer().at(id).setPosition(sf::Vector2f(std::get<0>(i).first, std::get<0>(i).second));
        _window.draw(getContainer().at(id).getSprite());
    }
}

void device::drawAll()
{
    _window.clear();
    drawSprite(0);
    _window.display();
};

EVENT device::event()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return (EVENT::QUIT);
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape)
                return (EVENT::QUIT);
        }
    }
    return EVENT::NONE;
};

sf::IntRect device::getRect(int x, int y, float max_x, float max_y)
{
    if (x == 0 && y == 0)
        return getContainer().at(0).roof.TopLeft;
    if (x == 0 && y != 0 && y != max_y)
        return getContainer().at(0).roof.MidLeft;
    if (x != 0 && x != max_x && y == 0)
        return getContainer().at(0).roof.TopMid;
    if (x >= max_x && y == 0)
        return getContainer().at(0).roof.TopRight;
    if (x == 0 && y >= max_y)
        return getContainer().at(0).roof.DownLeft;
    if (x != 0 && x != max_x && y >= max_y)
        return getContainer().at(0).roof.DownMid;
    if (x >= max_x && y >= max_y)
        return getContainer().at(0).roof.DownRight;
    if (x >= max_x && y != 0 && y != max_y)
        return getContainer().at(0).roof.MidRight;
    else
        return getContainer().at(0).roof.Mid;
}

void device::initmap(std::pair<int, int> size)
{
    _scale_x = (1920 / (double)size.first) / 16;
    _scale_y = (1080 / (double)size.second) / 16;
    double x = 0;
    double y = 0;
    std::vector<std::tuple<std::pair<double, double>, sf::IntRect ,ressource>> iMap = map.getVector();

    for (int i = 0; i < size.first; i++) {
        y = 0;
        for (int j = 0; j < size.second; j++) {
            for (auto &cell: _cellsContent)
                if (std::get<0>(cell) == i && std::get<1>(cell) == j)
                    iMap.push_back(std::make_tuple(std::make_pair(x, y), getRect(i, j, size.first-1, size.second-1), std::get<2>(cell)));
            y += (1080 / size.second);
        }
        x += (1920 / size.first);
    }
    map.setVector(iMap);
}

void device::setResponse()
{
    std::string tmp;

    while (!_responses.isEmpty()) {
        _responses.pop(tmp);
        _response.push_back(tmp);
        std::cout << tmp;
    }
}

void device::parseRessource()
{
    std::smatch matches;
    int x = 0;
    int y = 0;

    for (auto &str: _response) {
        for (auto &reg: _regexes) {
            auto res = std::regex_search(str, matches, reg);
            if (res) {
                std::string cmd(matches[1]);
                if (cmd == "sgt") {
                    int time = std::strtol(std::string(matches[2]).c_str(), nullptr, 10);
                    (void)time;
                } else if (cmd == "msz") {
                    _X = std::strtol(std::string(matches[2]).c_str(), nullptr, 10);
                    _Y = std::strtol(std::string(matches[3]).c_str(), nullptr, 10);
                } else if (cmd == "bct") {
                    ressource R;
                    R.R0 = std::strtol(std::string(matches[4]).c_str(), nullptr, 10);
                    R.R1 = std::strtol(std::string(matches[5]).c_str(), nullptr, 10);
                    R.R2 = std::strtol(std::string(matches[6]).c_str(), nullptr, 10);
                    R.R3 = std::strtol(std::string(matches[7]).c_str(), nullptr, 10);
                    R.R4 = std::strtol(std::string(matches[8]).c_str(), nullptr, 10);
                    R.R5 = std::strtol(std::string(matches[9]).c_str(), nullptr, 10);
                    R.R6 = std::strtol(std::string(matches[10]).c_str(), nullptr, 10);
                    _cellsContent.push_back(std::make_tuple(x, y, R));
                    y++;
                    if (y == _Y) {
                        x++;
                        y = 0;
                    }
                } else if (cmd == "tna") {
                    std::string team(matches[2]);
                    (void)team;
                }
            }
        }
    }
}

void device::init()
{
    Sprite roof;

    _container.push_back(roof);
    _regexes.push_back(std::regex("(sgt) ([0-9]+)"));
    _regexes.push_back(std::regex("(msz) ([0-9]+) ([0-9]+)"));
    _regexes.push_back(std::regex("(bct) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)"));
    _regexes.push_back(std::regex("(tna) (\\w+)"));
    parseRessource();
    randomFloor();
    initmap(std::make_pair(_X, _Y));
}

void device::run()
{
    int status = 1;

    createWindow();
    init();
    while(status != 0) {
        drawAll();
        if (event() == EVENT::QUIT)
            status = 0;
    }
    destroyWindow();
}