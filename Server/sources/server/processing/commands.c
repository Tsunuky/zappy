/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#include <stddef.h>
#include "commands.h"

const __command_t __command_tbl[] = {
    {"(Forward)", 1, CMD_NONE, OK, 7, &__cmd_forward},
    {"(Right)", 1, CMD_NONE, OK, 7, &__cmd_right},
    {"(Left)", 1, CMD_NONE, OK, 7, &__cmd_left},
    {"(Look)", 1, CMD_NONE, OTH, 7, &__cmd_look},
    {"(Inventory)", 1, CMD_NONE, OTH, 1, &__cmd_inventory},
    {"(Broadcast) (\\w+)", 2, CMD_PARAM, OK, 7, &__cmd_broadcast},
    {"(Connect_nbr)", 1, CMD_NONE, OTH, -1, &__cmd_connect},
    {"(Fork)", 1, CMD_NONE, OK, 42, &__cmd_fork},
    {"(Eject)", 1, CMD_NONE, OKKO, 7, &__cmd_eject},
    {"(Take) (\\w+)", 2, CMD_PARAM, OKKO, 7, &__cmd_take},
    {"(Set) (\\w+)", 2, CMD_PARAM, OKKO, 7, &__cmd_set},
    {"(Incantation)", 1, CMD_NONE, OK, 300, &__cmd_incantation},
    {NULL, -1, -1, -1, -1, NULL}
};