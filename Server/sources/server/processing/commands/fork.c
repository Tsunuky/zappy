/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include "commands.h"

__command_ret_t *__cmd_fork(__attribute__((unused)) const char *param,
__attribute__((unused)) const int32_t fd)
{
    dprintf(1, "ich bin fork\n");
    return (0);
}
