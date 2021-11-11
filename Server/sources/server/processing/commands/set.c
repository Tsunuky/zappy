/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "commands.h"

__command_ret_t *__cmd_set(const char *param, const int32_t fd)
{
    (void)fd;
    dprintf(1, "ich bin set(%s)\n", param);
    return (0);
}
