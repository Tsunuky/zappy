/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"

int __proto_eht(const int32_t fd, __player_t *player)
{
    char *output = NULL;

    asprintf(&output, "eht %d\n", player->__id);
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}
