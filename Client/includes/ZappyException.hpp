/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** zappyExeption
*/

#ifndef __ZAPPY_EXCPTION__HPP__
#define __ZAPPY_EXCPTION__HPP__

#include <exception>
#include <string>

enum class CException {
    ParsingException,
    GameException,
};

template <enum CException> class ZappyException : public std::exception{
private:
    std::string _errorMess;
public:
    ZappyException (const std::string &mess) : _errorMess(mess) {};
    virtual ~ZappyException() = default;
    virtual const char *what() const noexcept override {return _errorMess.c_str();};
};

#endif
