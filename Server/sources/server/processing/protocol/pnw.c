/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_pnw(const int32_t fd, __player_t *player)
{
    (void)fd;
    
    char *output = NULL;

    asprintf(&output, "pnw #%d %d %d %d %d %s", player->__id, player->__x,
    player->__y, player->__orientation, player->__level, player->__team);
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}
