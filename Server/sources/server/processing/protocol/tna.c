/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "game.h"

int __proto_tna(const char *param, const int32_t fd, __player_t *player)
{
    (void)param;
    (void)player;
    char *output = NULL;

    for (int i = 0; i != __team_arr->__size; i++) {
        asprintf(&output, "tna %s\n", __team_arr->__teams[i]->__name);
    }
    dprintf(fd, output);
    return (0);
}
