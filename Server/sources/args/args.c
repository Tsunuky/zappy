/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <malloc.h>
#include <string.h>
#include "args.h"

__args_t *__args = NULL;

char *concat_args(const char *const *const av)
{
    size_t length = 0;
    char *res = NULL;
    unsigned pos = 0;

    for (unsigned cpt = 0; av[cpt]; length += strlen(av[cpt]) + 1, cpt++);
    if (!(res = malloc((length + 1) * sizeof(char))))
        return (NULL);
    memset(res, 0, length);
    for (unsigned cpt = 0; av[cpt]; strcpy(res + pos, av[cpt]),
        strcpy(res + pos + strlen(av[cpt]), " "),
        pos += strlen(av[cpt]) + 1, cpt++);
    return (res);
}