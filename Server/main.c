/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "program.h"
#include "core.h"

int main(const int ac, const char *const *const av)
{
    return (constructor() != 0 || core(ac, av) != 0 ||
        destructor() != 0) ? 84 : 0;
}
