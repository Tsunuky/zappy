/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"

int __proto_pgt(const int32_t fd, __player_t *player, const int32_t rnumber)
{
    char *output = NULL;

    asprintf(&output, "pgt %d %d\n", player->__id, rnumber);
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}
