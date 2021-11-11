/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"

int __proto_enw(const int32_t fd, __player_t *player)
{
    char *output = NULL;

    asprintf(&output, "enw %d %d %d %d\n", player->__id, player->__id, 
    player->__x, player->__y);
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}
