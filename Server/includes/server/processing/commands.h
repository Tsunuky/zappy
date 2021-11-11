/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** zappy
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdint.h>
#include <stdio.h>

typedef enum __s_command_ret
{
    NORET, OKKO, OK, KO, OTH
} __command_ret_t;

typedef enum __s_command_params
{
    CMD_NONE, CMD_PARAM
} __command_params_t;

typedef struct __s_command
{
    const char *__expr;
    const uint32_t __groups;
    const __command_params_t __params;
    const __command_ret_t __ret;
    const int32_t __time;
    __command_ret_t *(*__fcn)(const char *, const int32_t);
} __command_t;

extern const __command_t __command_tbl[];

__command_ret_t *__cmd_forward(const char *, const int32_t);
__command_ret_t *__cmd_right(const char *, const int32_t);
__command_ret_t *__cmd_left(const char *, const int32_t);
__command_ret_t *__cmd_look(const char *, const int32_t);
__command_ret_t *__cmd_inventory(const char *, const int32_t);
__command_ret_t *__cmd_broadcast(const char *, const int32_t);
__command_ret_t *__cmd_connect(const char *, const int32_t);
__command_ret_t *__cmd_fork(const char *, const int32_t);
__command_ret_t *__cmd_eject(const char *, const int32_t);
__command_ret_t *__cmd_take(const char *, const int32_t);
__command_ret_t *__cmd_set(const char *, const int32_t);
__command_ret_t *__cmd_incantation(const char *, const int32_t);

// Forward / 1 tile forward advancement / no param / ok / (7/f)
// Right / turn 90° right / no param / ok / (7/f)
// Left / turn 90° left / no param / ok / (7/f)
// Look / look around / no param / __tiles[] / (7/f)
// Inventory / open inventory / no param / __inventory[__material nbr] / (1/f)
// Broadcast text / broadcast / text / ok / (7/f)
// Connect_nbr / number of unused slot  for current team / no param / nbr / -
// Fork / fork a player / no param / ok / (42/f)
// Eject / eject all player from current tile / no param / (ok/ko) / (7/f)
// - / death of player / no param / dead / -
// Take object / take an object / object / (ok/ko) / (7/f)
// Set object / drop an object / object / (ok/ko) / (7/f)
// Incantation / start incantation / no param / (Elevation underway\tCurrent level: lvl/ko) / (300/f)

#endif
