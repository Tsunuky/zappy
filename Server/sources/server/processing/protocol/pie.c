/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_pie(const int32_t fd, __player_t *player)
{
    char *output = NULL;

    asprintf(&output, "pie %d %d %d", player->__x, player->__y, 
    player->__incantation);
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}