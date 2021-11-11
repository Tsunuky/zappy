/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"

int __proto_pin(const char *param, const int32_t fd, __player_t *player)
{
    (void)param;
    (void)fd;

    char *output = NULL;
    __materials_t *inventory = player->__inventory;

    asprintf(&output, "pin %d %d %d %d %d %d %d %d %d %d\n", player->__id,
    player->__x, player->__y, inventory->__food, inventory->__linemate,
    inventory->__deraumere, inventory->__sibur, inventory->__mendiane,
    inventory->__phiras, inventory->__thystame);
    dprintf(fd, output);
    return (0);
}
