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

static char **tab(char *names)
{
    char **ret = NULL;
    int spaces = 0;
    unsigned cpt = 0;

    for (char *tmp = names + 3; *tmp; tmp++)
        spaces += (*tmp == ' ' ? 1 : 0);
    if (!(ret = malloc((spaces + 2) * sizeof(char *))))
        return (NULL);
    ret[spaces + 1] = NULL;
    for (char *str = strtok(names + 3, " "); str; str = strtok(NULL, " "))
        ret[cpt++] = strdup(str);
    free(names);
    return (ret);
}

int args_parser(const char *const *const av)
{
    const char *expr = "\\.\\/\\w+ (-p [0-9]+) (-x [0-9]+) (-y [0-9]+) " \
        "(-n \\w+( \\w+)*) (-c [0-9]+) (-f [0-9]+)";
    char *avstr = concat_args(av);
    __attribute__((cleanup(regfree))) regex_t regex;
    regmatch_t matches[8];

    regcomp(&regex, expr, REG_EXTENDED);
    regexec(&regex, avstr, 8, matches, 0);
    __args->__port = strtol(avstr + matches[1].rm_so + 3, NULL, 10);
    __args->__width = strtol(avstr + matches[2].rm_so + 3, NULL, 10);
    __args->__height = strtol(avstr + matches[3].rm_so + 3, NULL, 10);
    __args->__names = tab(strndup(avstr + matches[4].rm_so,
        matches[4].rm_eo - matches[4].rm_so));
    __args->__clients = strtol(avstr + matches[6].rm_so + 3, NULL, 10);
    __args->__freq = strtol(avstr + matches[7].rm_so + 3, NULL, 10);
    free(avstr);
    return (__args->__port < 0 || __args->__port > 65535 ||
        __args->__width <= 0 || __args->__height <= 0 ||
        (!__args->__names) || __args->__clients <= 0) ? 84 : 0;
}
