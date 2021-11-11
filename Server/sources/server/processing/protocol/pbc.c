/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_pbc(const int32_t fd, __player_t *player)
{
    (void)fd;
    char *output = NULL;

    asprintf(&output, "pbc %d %s\n", player->__id, player->__message);
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}
