/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_ppo(const char *param, const int32_t fd, __player_t *player)
{
    (void)param;
    (void)fd;

    char *output = NULL;

    asprintf(&output, "ppo %d %d %d %d\n", player->__id, player->__x, 
    player->__y, player->__orientation);
    dprintf(fd, output);
    return (0);
}
