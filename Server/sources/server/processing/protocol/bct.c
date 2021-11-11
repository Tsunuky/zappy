/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_bct(const char *param, const int32_t fd, __player_t *player)
{
    (void)param;
    (void)player;

    char *output = NULL;
    __materials_t *materials = __map->__cells[__map->__width * __map->__height]
    ->__materials;

    asprintf(&output, "bct %d %d %d %d %d %d %d %d %d\n",
    __map->__width, __map->__height, materials->__food, materials->__linemate,
    materials->__deraumere, materials->__sibur, materials->__mendiane,
    materials->__phiras, materials->__thystame);
    dprintf(fd, output);
    return (0);
}
