/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_pdr(const int32_t fd, __player_t *player, const int32_t rnumber)
{
    char *output = NULL;

    asprintf(&output, "pdr %d %d\n", player->__id, rnumber);
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}
