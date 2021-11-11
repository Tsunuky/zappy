/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "args.h"

int check_help(const int ac, const char *const *const av)
{
    return (ac == 2 && strncmp(av[1], "-help", 5) == 0) ? 0 : 1;
}

int check_args(const char *const *const av)
{
    const char *expr = "\\.\\/\\w+ (-p [0-9]+) (-x [0-9]+) (-y [0-9]+) " \
        "(-n \\w+( \\w+)*) (-c [0-9]+) (-f [0-9]+)";
    __attribute__((cleanup(regfree))) regex_t regex;
    char *avstr = NULL;
    int ret = 0;

    if (!(avstr = concat_args(av)))
        return (84);
    regcomp(&regex, expr, REG_EXTENDED);
    ret = (regexec(&regex, avstr, 0, NULL, 0) == 0 ? 0 : 84);
    free(avstr);
    return (ret);
}