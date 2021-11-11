/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"
#include "args.h"

int __proto_sgt(const char *param, const int32_t fd, __player_t *player)
{
    (void)param;
    (void)player;
    char *output = NULL;

    asprintf(&output, "sgt %d", __args->__tunit);
    dprintf(fd, output);
    return (0);
}
