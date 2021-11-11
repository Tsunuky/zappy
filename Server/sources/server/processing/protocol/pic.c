/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_pic(const int32_t fd, __player_t *player)
{
    dprintf(fd, "pic %d %d %d ", player->__x, player->__y,
    player->__level);
    for (int i = 0; i != __player_arr->__size; i++)
        if (__player_arr->__players[i]->__x == player->__x &&
        __player_arr->__players[i]->__y == player->__y) {
            dprintf(fd, "%d ", __player_arr->__players[i]->__id);
        }
    dprintf(fileno(stderr), "pic %d %d %d ", player->__x, player->__y,
    player->__level);
    for (int i = 0; i != __player_arr->__size; i++)
        if (__player_arr->__players[i]->__x == player->__x &&
        __player_arr->__players[i]->__y == player->__y) {
            dprintf(fileno(stderr), "%d ", __player_arr->__players[i]->__id);
        }
    return (0);
}
