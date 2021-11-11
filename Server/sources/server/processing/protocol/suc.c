/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "protocol.h"

int __proto_suc(const int32_t fd, __player_t *player)
{
    (void)player;
    char *output = NULL;

    asprintf(&output, "suc\n");
    dprintf(fd, output);
    dprintf(fileno(stderr), output);
    return (0);
}
