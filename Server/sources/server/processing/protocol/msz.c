/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "args.h"
#include "game.h"

int __proto_msz(__attribute__((unused))const char *param, const int32_t fd, __player_t *player)
{
    (void)player;
    char *output = NULL;

    asprintf(&output, "msz %d %d", __map->__width, __map->__height);
    dprintf(fd, output);
    return (0);
}
