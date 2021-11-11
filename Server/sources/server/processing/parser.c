/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <errno.h>
#include <regex.h>
#include <stddef.h>
#include "commands.h"
#include "protocol.h"

static int regparse(const char *const expr, char *buffer,
const int32_t groups, char **res)
{
    __attribute__((cleanup(regfree))) regex_t regex;
    regmatch_t matches[groups + 1];

    if (regcomp(&regex, expr, REG_EXTENDED) != 0)
        return (84);
    if (regexec(&regex, buffer, groups, matches, 0) != 0)
        return (-1);
    if (groups == 1)
        return (0);
    if (groups == 2 || groups == 3) {
        *res = &buffer[matches[1].rm_eo + 1];
        return (0);
    }
    return (-1);
}

int parser(const int32_t fd, const char *const buffer)
{
    int ret = 0;
    char *res = NULL;

    for (int32_t cpt = 0; __command_tbl[cpt].__expr != NULL; cpt++) {
        ret = regparse(__command_tbl[cpt].__expr, (char *)buffer,
            __command_tbl[cpt].__groups, &res);
        if (ret == -1)
            continue ;
        else if (ret == 84)
            return (84);
        if (__command_tbl[cpt].__fcn(res, fd) != 0)
            return (84);
        res = NULL;
    }
    for (int32_t cpt = 0; __protocol_tbl[cpt].__expr != NULL; cpt++) {
        ret = regparse(__protocol_tbl[cpt].__expr, (char *)buffer,
            __protocol_tbl[cpt].__groups, &res);
        if (ret == -1)
            continue ;
        else if (ret == 84)
            return (84);
        if (__protocol_tbl[cpt].__fcn(res, fd, NULL) != 0)
            return (84);
        res = NULL;
    }
    return (-1);
}