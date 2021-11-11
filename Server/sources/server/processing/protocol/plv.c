/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"

int __proto_plv(const char *param, const int32_t fd, __player_t *player)
{
    (void)param;
    (void)fd;

    char *output = NULL;
    asprintf(&output, "plv %d %d\n", player->__id, player->__level);
    dprintf(fd, output);
    return (0);
}
