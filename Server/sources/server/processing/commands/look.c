/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "commands.h"

__command_ret_t *__cmd_look(__attribute__((unused)) const char *param,
const int32_t fd)
{
    (void)fd;
    dprintf(1, "ich bin look\n");
    return (0);
}
