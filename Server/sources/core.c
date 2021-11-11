/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "server.h"
#include "game.h"
#include "args.h"

int core(const int ac, const char *const *const av)
{
    return (check_help(ac, av) == 0 ? help(av[0]) :
        (check_args(av) != 0 || args_parser(av) != 0 ||
        map_create() != 0 || server() != 0 || loop() != 0) ? 84 : 0);
}